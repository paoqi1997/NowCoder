# Answers for NowCoder

习题答案。

## NetEase

### 1. [彩色的砖块](https://www.nowcoder.com/questionTerminal/8c29f4d1bea84d6ba2847e079b7420f7)

题目分析：最多存在一对不同颜色的相邻砖块，也就是两组不同颜色的砖块。去重后，如果还剩下3种或以上不同的颜色，则不合题意；如果还剩下2种颜色，则有两组不同颜色的砖块，如AABB或BBAA，对应有2种排法；如果还剩下1种颜色，则有一组砖块，如AA，对应有1种排法；如果没有颜色剩下，也不符合题意。

### 2. [等差数列](https://www.nowcoder.com/questionTerminal/e11bc3a213d24fc1989b21a7c8b50c3f)

题目分析：略。

### 3. [交错01串](https://www.nowcoder.com/questionTerminal/3fbd8fe929ea4eb3a254c0ed34ac993a)

题目分析：略。

### 4. [操作序列](https://www.nowcoder.com/questionTerminal/b53bda356a494154b6411d80380295f5)

题目分析：找出规律即可。

### 5. [独立的小易](https://www.nowcoder.com/questionTerminal/a99cdf4e2f44499e80749699cc2ec2b9)

题目分析：分情况讨论即可。

### 6. [小易喜欢的数列](https://www.nowcoder.com/questionTerminal/49375dd6a42d4230b0dc4ea5a2597a9b)

题目分析：动态规划，其中递推方程为dp[i][j] += dp[i - 1][l]，其中1 <= l <= k。

### 7. [疯狂队列](https://www.nowcoder.com/questionTerminal/d996665fbd5e41f89c8d280f84968ee1)

题目分析：这里要求绝对值最大，那么我们先得到一个升序序列，然后自左右向中间逼近，并在此期间计算疯狂值，最后得到结果。

### 8. [最小众倍数](https://www.nowcoder.com/questionTerminal/3e9d7d22b7dd4daab695b795d243315b)

题目分析：略。

### 9. [缩写](https://www.nowcoder.com/questionTerminal/45083499b8c5404fb1db44c6ea4f170a)

题目分析：略。

### 10. [数位重排](https://www.nowcoder.com/questionTerminal/f970201e9f7e4040ab25a40918e27d15)

题目分析：略。

### 11. [数轴](https://www.nowcoder.com/questionTerminal/ff0e55dcb75b45b09164c56f87cdf737)

题目分析：相邻两点中左边的点记为l，右边的点记为r，最左边的点记为ll，最右边的点记为rr，点ll向右推进，点r投靠左边，计入左端；点rr向左推进，点l投靠右边，计入右端，由此计算左右之间的距离。

### 12. [骰子游戏](https://www.nowcoder.com/questionTerminal/0e83797c34e54cca91179fe9ad681bc4)

题目分析：动态规划，其中递推方程为dp[i][j] += dp[i - 1][j - k]，其中i <= j <= 6 * i，1 <= k <= 6。
