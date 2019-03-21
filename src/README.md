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

## G-bits

### 1. [求素数](https://www.nowcoder.com/questionTerminal/ea1c82be0c144d74925a044973fe9a5c)

题目分析：素数的倍数一定不是素数。

### 2. [最大差值](https://www.nowcoder.com/questionTerminal/c1ad0923a49b4347bd0bf8070610d046)

题目分析：桶排序。

### 3. [字母数字混合排序](https://www.nowcoder.com/questionTerminal/6d27688e056c491b9024fa1340404666)

题目分析：略。

### 4. [走格子游戏](https://www.nowcoder.com/questionTerminal/e15b45484ff049ddb84fa1b8d309948c)

题目分析：深搜，为避免游戏失败，行动力在任何时候都应大于0，我们一开始应将重心放在行动力的谷值，然后选择行动力的谷值最高的路线。

## ChangYou

### 1. [数据分页说明](https://www.nowcoder.com/questionTerminal/b6c448328c4f486d8cce39245889cdfe)

题目分析：略。

### 2. [第二大的数](https://www.nowcoder.com/questionTerminal/ce710d3a27ca475b97bbae0cb227f1b5)

题目分析：略。

## XunLei

### 1. [2的N次方](https://www.nowcoder.com/questionTerminal/e9a4919b8848451d9aff81e3cdd133b1)

题目分析：大数运算。

### 2. [整数反转](https://www.nowcoder.com/questionTerminal/14733e0bfa9b474ba7cbe0bb2e459731)

题目分析：略。

### 3. [整数求和](https://www.nowcoder.com/questionTerminal/6701fc9b1be84bafac1091705df2e0b4)

题目分析：见下。

#### 1. 动态规划

dp[i][j]为在[1, ..., i]中取若干个整数求和等于 j 的组合数。

```cpp
for (int i = 0; i <= n; ++i) {
    dp[i][0] = 1;
}
for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
        if (j - i >= 0) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i];
        } else {
            dp[i][j] = dp[i - 1][j];
        }
    }
}
```

#### 2. 01背包

dp[j]为背包容量等于 j 时物品的价值总和，由于物品的重量就是物品的价值，故只需要维护一张一维表。

```cpp
dp[0] = 1;
for (int i = 1; i <= n; ++i) {
    for (int j = m; j >= i; --j) {
        dp[j] += dp[j - i];
    }
}
```

## Ke

### 1. [乔乔的包](https://www.nowcoder.com/questionTerminal/a16b6679cc1841c3a20324279116d040)

题目分析：01背包。

### 2. [小明卖食物](https://www.nowcoder.com/questionTerminal/fba13a9bd7ad4bfaa02cefbc2512aaae)

题目分析：略。

### 3. [倒水](https://www.nowcoder.com/questionTerminal/8ffeb301d208490aaf5b9f9556e951ab)

题目分析：如下。

#### 1. 动态规划

```cpp
for (int i = 0; i <= m; ++i) {
    dp[i][1] = 1;
}
for (int j = 0; j <= n; ++j) {
    dp[0][j] = 1;
}
for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
        if (j > i) {
            dp[i][j] = dp[i][i];
        } else {
            dp[i][j] = dp[i][j - 1] + dp[i - j][j];
        }
    }
}
```

#### 2. m个苹果放入n个盘子

```cpp
int fn(int m, int n) {
    if (m == 0 || n == 1) {
        return 1;
    }
    if (n > m) {
        return fn(m, m);
    } else {
        return fn(m, n - 1) + fn(m - n, n);
    }
}
```

### 4. [斐波那契数列](https://www.nowcoder.com/questionTerminal/c245af6cfdce49ceb5435f649ee14f89)

题目分析：略。

## KuGou

### 1. [买橘子](https://www.nowcoder.com/questionTerminal/73e0552b78474a9086781e47f4e01d73)

题目分析：略。

## TuNiu

### 1. [最长公共子串](https://www.nowcoder.com/questionTerminal/5bb66d2ceb3a433aa6e1c3e254554b15)

题目分析：略。
