import os
import json
import re

def remove_comments(code):
    # 去除多行注释 /* ... */
    code = re.sub(r'/\*.*?\*/', '', code, flags=re.DOTALL)
    # 去除单行注释 // ...
    lines = code.split('\n')
    lines = [line for line in lines if not line.strip().startswith('//')]
    # 重新合并为字符串
    return '\n'.join(lines)

def analyze_c_code(file_path):
    with open(file_path, 'r') as file:
        raw_code = file.read()
        # 去除注释后的代码
        code = remove_comments(raw_code)
        lines = code.split('\n')
        # 过滤空行
        non_empty_lines = [line for line in lines if line.strip()]
        
        # 初始化特征
        features = {
            "loc": len(non_empty_lines),  # 只计算非空行和非注释行
            "num_functions": 0,
            "nesting_depth": 0,
            "num_conditional_statements": 0,
            "num_variables": 0,
            "function_call_count": 0,
            "cyclomatic_complexity": 1,
            "memory_operations": 0
        }
        
        # 正则表达式模式
        function_pattern = r'(int|void|char|float|double)\s+(\w+)\s*\([^)]*\)\s*{'
        loop_pattern = r'(for|while|do)\s*[\({]'
        cond_pattern = r'\b(if|else if|else|switch)\b'
        var_pattern = r'(int|char|float|double)\s+\w+\s*(=|[;])'
        func_call_pattern = r'\b\w+\s*\([^)]*\)'
        mem_op_pattern = r'\b(malloc|calloc|realloc|free)\s*\('
        
        # 计算函数数量，并提取函数名
        function_matches = re.findall(function_pattern, code)
        features["num_functions"] = len(function_matches)
        function_names = [match[1] for match in function_matches]  # 提取函数名
        
        # 计算循环嵌套深度
        nesting_level = 0
        max_nesting = 0
        for line in lines:
            if re.search(loop_pattern, line):
                nesting_level += 1
                max_nesting = max(max_nesting, nesting_level)
            elif '}' in line:
                nesting_level = max(0, nesting_level - 1)
        features["nesting_depth"] = max_nesting
        
        # 计算条件语句数量
        features["num_conditional_statements"] = len(re.findall(cond_pattern, code))
        
        # 计算变量数量
        features["num_variables"] = len(re.findall(var_pattern, code))
        
        # 计算函数调用次数
        func_calls = re.findall(func_call_pattern, code)
        # 排除函数定义，只保留真正的调用
        features["function_call_count"] = len([call for call in func_calls 
                                              if not any(call.startswith(name + '(') 
                                                        for name in function_names)])
        
        # 计算圈复杂度
        features["cyclomatic_complexity"] += (features["num_conditional_statements"] + 
                                            features["nesting_depth"])
        
        # 计算内存操作次数
        features["memory_operations"] = len(re.findall(mem_op_pattern, code))
        
        return features

def process_directory(directory_path, output_file):
    with open(output_file, 'w') as out:
        for filename in os.listdir(directory_path):
            if filename.endswith('.c'):
                file_path = os.path.join(directory_path, filename)
                features = analyze_c_code(file_path)
                out.write(f"# Analysis for {filename}\n")
                out.write(json.dumps(features, indent=4) + "\n\n")

# 示例用法
if __name__ == "__main__":
    directory = "/Users/zhuo/Desktop/Github/parf_test_src/"  # 替换为你的C文件目录
    output_file = "analysis_results.txt"  # 输出文件路径
    process_directory(directory, output_file)
    print(f"Analysis complete. Results written to {output_file}")
