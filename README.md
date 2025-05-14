### 仓库结构

- `train_set`: 训练集
  - `analysis_results`存放了（部分）训练集程序各自的特征；
  - 与parf的分析结果组成 特称-参数设置的数据集
- `test_set`: 测试集
  - 在 `confit.md`文件中包含了对改文件结构的详细说明，包括如何得到初始参数等
- `utils`: 存放机器学习相关的源码(code)， 以及数据处理的文件



### 测试过程相关点

- 为了实验可复现，我将训练集和测试集都放在了[本仓库](https://github.com/ffy6511/parf_dataset.git)

#### 测试集的选取

- 主要来源(7/12)：[OSCS](https://github.com/Frama-C/open-source-case-studies.git)
  - `2048.c`用于训练，没有参与测试，
  - 通过筛查剩下的文件，找到文件结构较简单的进行测试；
- [Juliet_Test](https://gitlab.com/sosy-lab/benchmarking/sv-benchmarks/-/tree/main/c/Juliet_Test/Juliet_Test_Suite_v1.3_for_C_Cpp/C?ref_type=heads)
  - 发现好像都比较简单，
  - 如果比例太高的话，我们的方法应该都会以时间较短且低误报胜出，因此我控制了比例（选择了2个），
- [The Stack](https://huggingface.co/datasets/bigcode/the-stack)
  - 请wyx在the stack上找到部分文件，然后筛除简单的，留下3份较为复杂的程序；
  - 具体来源已缺失，但是已经存放在仓库中



#### 测试进行的环境

- mac上通过docker安装Parf



#### 测试过程

- 对所有的测试集，Parf均至少进行5,15min上限的分析
  - 如果程序较复杂/误报数目较多，将继续进行30min上限的parf分析
- 用FDMT预测得到的参数进行一次的eva分析



#### 测试结果图像的解释

- `5#`表示时间预算为5min，其余同理

- 数据处理
  - **加粗+红色高亮**：FDMT的测试表现完全优于parf的三组结果（误报数目等于前三组的最低数，且时间大幅缩短）
  - **红色高亮**： 
    - FDMT的测试表现完全优于parf的前两组结果 
    - 或 FDMT的测试表现在误报上显著较优
  - **下划线**：表示得出FDMT较优结论，所参与计算的数据
    - 比如在parf三组误报完全相同的情况下，我们用 `#5`的parf时间与FDMT进行比较

<img src="https://my-blog-img-1358266118.cos.ap-guangzhou.myqcloud.com/undefineda0f6a16c4f3462ece815c775ff8d4769.png?imageSlim"/>
