﻿电梯升降问题
--------------------

###问题描述
       一栋10层的大楼（楼层编号1-10），设有一台无限载重的电梯，初始时电梯停在1层。电梯移动1层的耗时为1，在某一层停靠的耗时为1（时间初始为0）。为了使得乘客等待的时间（电梯在目的层的停靠时刻 - 乘客发出请求时刻）总和最小，请你编写一个程序来进行电梯调度。

输入有``5个请求``，每个请求一行，格式为``请求时刻`` ``起始楼层数 `` ``去往方向``，其中方向为**0**代表向上去往**10**层，为**1**代表向下去往**1**层。
输出每次对应的决策，每一行的输出格式为``xx时，停靠在x楼``。其中，**“xx时刻”**指的是在某层楼停靠的时刻，且不算入在该层的停靠时间。如：

>当0时刻时，电梯此时在1层，输入有0 1 0，那么电梯从1层接客（1s）前往10层（9s），应输出10时，停靠在10楼（1+9=10）。此时，该乘客等待时间为(10-0=)10。

>当0时刻，电梯此时在1层，输入有0 2 0，那么电梯从1层前往2层（1s），接上乘客（1s），前往10层（8s），应输出10时，停靠在10楼（1+1+8=10）。此时，该乘客等待时间为(10-0=)10s。

最后输出完成5个请求（所有乘客都到达目的地）后，各乘客的等待时间总和。
请自己设计5组测试用例，且具有一定代表性，用以验证程序是否是最小耗时。

###想法思路
    思路A: 以时间为轴，对每个时间点求最优贪心策略，贪心策略为 电梯三种操作方式（向上向下停靠）中对乘客最优的策略。
    思路B: 以乘客为轴，对每个乘客按电梯门按钮时的情况DFS找最优解。

思路A的优点在于代码耗时短，以时间轴来判断更符合电梯在现实中的实际情况，缺点在于不能保证运行结果最优。
思路B的优点在于答案保证最优，深搜将所有情况攘括其中，缺点在于运行速度偏慢，代码耗时长。
