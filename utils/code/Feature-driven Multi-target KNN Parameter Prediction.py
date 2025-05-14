import numpy as np
from sklearn.neighbors import KNeighborsRegressor
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import cross_val_score
import json
from flask import Flask, request, jsonify
from data import data

# 初始化 Flask 应用
app = Flask(__name__)

# 提取特征和目标
X = np.array([[d["features"]["loc"], d["features"]["num_functions"], d["features"]["nesting_depth"],
               d["features"]["num_conditional_statements"], d["features"]["num_variables"],
               d["features"]["function_call_count"], d["features"]["cyclomatic_complexity"],
               d["features"]["memory_operations"]] for d in data])

y_numeric = np.array([[d["parameters"]["widening_delay"], d["parameters"]["subdivide_non_linear"],
                       d["parameters"]["slevel"], d["parameters"]["plevel"], d["parameters"]["partition_history"],
                       d["parameters"]["min_loop_unroll"], d["parameters"]["ilevel"],
                       d["parameters"]["auto_loop_unroll"]] for d in data])

equality_map = {"none": 0, "formals": 1}
y_equality = np.array([equality_map[d["parameters"]["equality_through_calls"]] for d in data])

domains_list = ["cvalue", "equality", "gauges", "octagon", "symbolic-locations"]
y_domains = np.array([[1 if domain in d["parameters"]["domains"] else 0 for domain in domains_list] for d in data])

# 归一化
scaler_X = StandardScaler()
X_scaled = scaler_X.fit_transform(X)

scaler_y = StandardScaler()
y_numeric_scaled = scaler_y.fit_transform(y_numeric)

# 评估不同k值的表现
print("开始评估不同k值的表现...")
k_values = [1, 3, 5, 7]
best_score = -float('inf')
best_k = None

for k in k_values:
    knn = KNeighborsRegressor(n_neighbors=k, weights='distance')
    scores = cross_val_score(knn, X_scaled, y_numeric_scaled, cv=5)
    mean_score = scores.mean()
    std_score = scores.std()
    print(f"k={k}, 平均得分: {mean_score:.3f} (+/- {std_score * 2:.3f})")
    
    if mean_score > best_score:
        best_score = mean_score
        best_k = k

print(f"\n推荐使用 k={best_k} (最佳平均得分: {best_score:.3f})")

# 使用最佳k值训练最终模型
knn_numeric = KNeighborsRegressor(n_neighbors=best_k, weights='distance')
knn_numeric.fit(X_scaled, y_numeric_scaled)

knn_equality = KNeighborsRegressor(n_neighbors=best_k, weights='distance')
knn_equality.fit(X_scaled, y_equality)

knn_domains = KNeighborsRegressor(n_neighbors=best_k, weights='distance')
knn_domains.fit(X_scaled, y_domains)

# 预测函数
def predict_parameters(features):
    features_array = np.array([[features["loc"], features["num_functions"], features["nesting_depth"],
                                features["num_conditional_statements"], features["num_variables"],
                                features["function_call_count"], features["cyclomatic_complexity"],
                                features["memory_operations"]]])
    features_scaled = scaler_X.transform(features_array)

    numeric_scaled = knn_numeric.predict(features_scaled)
    numeric = scaler_y.inverse_transform(numeric_scaled)[0]

    equality_pred = int(round(knn_equality.predict(features_scaled)[0]))
    equality = "formals" if equality_pred == 1 else "none"

    domains_pred = knn_domains.predict(features_scaled)[0]
    domains = [domains_list[i] for i, pred in enumerate(domains_pred) if pred > 0.5]

    params = (
        f"-eva-widening-delay {int(numeric[0])} "
        f"-eva-subdivide-non-linear {int(numeric[1])} "
        f"-eva-slevel {int(numeric[2])} "
        f"-eva-remove-redundant-alarms "
        f"-eva-plevel {int(numeric[3])} "
        f"-eva-partition-history {int(numeric[4])} "
        f"-eva-min-loop-unroll {int(numeric[5])} "
        f"-eva-ilevel {int(numeric[6])} "
        f"-eva-equality-through-calls {equality} "
        f"-eva-domains {','.join(domains)} "
        f"-eva-auto-loop-unroll {int(numeric[7])}"
    )
    if features["num_functions"] > 1:
        params += " -eva-split-return auto"

    return {
        "parameters": params,
        "features": f"loc={features['loc']}, nesting={features['nesting_depth']}, complexity={features['cyclomatic_complexity']}",
        "notes": f"Predicted based on KNN model with k={best_k}"
    }

# Flask 路由
@app.route('/')
def home():
    return jsonify({"message": "Welcome to the EVA Parameter Prediction API. Use POST /predict to get predictions."})

@app.route('/predict', methods=['POST'])
def predict():
    try:
        features = request.get_json()
        if not features:
            return jsonify({"error": "No JSON data provided"}), 400

        result = predict_parameters(features)
        return jsonify(result)
    except Exception as e:
        return jsonify({"error": str(e)}), 500

# 运行 Flask 应用
if __name__ == "__main__":
    app.run(host='0.0.0.0', port=5000)
