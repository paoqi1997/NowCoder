# NowCoder

个人整理的知识笔记及习题技巧（C/C++后端方向）。

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

## C/C++

1. [delete this](https://www.nowcoder.com/questionTerminal/45bb35c18c434829af740c0d843fcb1e)

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

可以在类的成员函数中delete this，delete之后也可调用该对象的其他方法，但前提是不涉及this指针的内容。

2. [char](https://www.nowcoder.com/questionTerminal/3327439779e146dc9035b0977d9469eb)

```cpp
signed char a = 0xe0;
unsigned int b = a;
unsigned char c = a;
```

a的原码为1110 0000，反码为1001 1111，补码为1010 0000，故a为-32，A错；c的补码为1110 0000，故c为224，c不等于a，B错；b为0xffffffe0，正确，故选C。

|   |MIN|MAX|
|---|---|---|
| char | -128 | 127 |
|unsigned char|0|255|

3. [short](https://www.nowcoder.com/questionTerminal/b7dd8b9cf69e4554912a45bdae9a8bda)

```cpp
short si = -32767;
unsigned short usi = si;
```

si的原码为1111 1111 1111 1111，反码为1000 0000 0000 0000，补码为1000 0000 0000 0001，usi的补码也为1000 0000 0000 0001，1从符号位转换为数值位，故选D。

|   |MIN|MAX|
|---|---|---|
| short | -32768 | 32767 |
|unsigned short|0| 65535 |

3. [array](https://www.nowcoder.com/questionTerminal/0959b5b04e7842adb74ddf071c3fa52f)

定义二维数组时可以省略第一维的大小，故选A。

```cpp
int m[][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
```

4. operator priority

[Question 1](https://www.nowcoder.com/questionTerminal/58769985d07646368f73e53a10c862f9)

选D。

[Question 2](https://www.nowcoder.com/questionTerminal/3567b8a580b74315bd2a463c7d686d6d)

选B。

[Question 3](https://www.nowcoder.com/questionTerminal/ea662448f3f043d1a165ae31e647dae3)

选C。

++（后置递增） <---- ++（前置递增） <---- ! <--- + <---- != <--- &（逻辑与） <---- && <---- ? :

5. [printf](https://www.nowcoder.com/questionTerminal/316082aaacfe4c3f8faf004e3e0fcf6d)

```cpp
int main() {
    int a; float b, c;
    scanf("%2d%3f%4f", &a, &b, &c);
    printf("\na=%d,b=%d,c=%f", a, b, c);
}
```

printf将参数自右向左依次压入堆栈，其中a是4个字节，b和c被提升为double类型，是8个字节。随后依次出栈，a打印4个字节，读取到的是98；而b打印4个字节，在小端存储方式下，低地址低位，高地址高位，栈顶至栈底为地址增长的方向，故b读取到的是0；c打印8个字节，后4个字节并不是0，但因太小而被忽略，读取到的也是0，故选B。
