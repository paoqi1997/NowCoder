# NowCoder

个人整理的知识笔记及习题技巧（C++后端方向）。

## Computer Basis

1. 原码、反码及补码

正数的原码、反码及补码均相同，而负数的原码就是在其正数的原码的基础上，符号位取1；负数的反码就是在其原码的基础上，除符号位，其余位取反；负数的补码就是在其反码的基础上+1。

|   | 原码 | 反码 | 补码 |
|---|---|---|---|
| +128 | 1000 0000 | 1000 0000 | 1000 0000 |
| +127 | 0111 1111 | 0111 1111 | 0111 1111 |
| +0   | 0000 0000 | 0000 0000 | 0000 0000 |
| -0   | 1000 0000 | 1111 1111 | 0000 0000 |
| -127 | 1111 1111 | 1000 0000 | 1000 0001 |
| -128 | 1000 0000 | 1111 1111 | 1000 0000 |

## C++

1. [delete this](https://www.nowcoder.com/questionTerminal/45bb35c18c434829af740c0d843fcb1e)

可以在类的成员函数中delete this，delete之后也可调用该对象的其他方法，但前提是不涉及this指针的内容。

```cpp
class A {
public:
    A() = default;
    void func() { delete this; }
};
...
A a;
a.func();
```

2. [signed char](https://www.nowcoder.com/questionTerminal/3327439779e146dc9035b0977d9469eb)

a为符号类型，范围为-128 ~ 127，0xe0的原码为1110 0000，反码为1001 1111，补码为1010 0000，故a为-32，A错；c为无符号类型，范围为0 ~ 255，故c为224，不等于a，B错；b为0xffffffe0，正确，故选C。

```
signed char a = 0xe0;
unsigned int b = a;
unsigned char c = a;
```