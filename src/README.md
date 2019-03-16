# Answers on NowCoder

习题答案。

## NetCase

### 1. [彩色的砖块](https://www.nowcoder.com/questionTerminal/8c29f4d1bea84d6ba2847e079b7420f7)

题目分析：最多存在一对不同颜色的相邻砖块，也就是两组不同颜色的相邻砖块。去重后，如果还剩下3种或以上不同的颜色，则不合题意；如果还剩下2种颜色，则有2种排法，如AABB或BBAA；如果还剩下1种颜色，则有1种排法，如AA，如果不剩下，也不符合题意。
