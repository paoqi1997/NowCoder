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

[Question 1](https://www.nowcoder.com/questionTerminal/92620388e2754b72950ca939d6493300)

a + b = 0x 7FFF FFFF FFFF FFFF + 0x 8000 0000 0000 0000 = 0x FFFF FFFF FFFF FFFF，负数在计算机中的存储形式为补码，故先-1再取反得到原码，最终为-1，故选B。

2. 字节对齐

[Question 1](https://www.nowcoder.com/questionTerminal/17e34bb0d97b4ef99f4b69458194c662)

```cpp
struct stu
{
    union {
        char bj[5];
        int bh[2];
    } class;
    char xm[8];
    float cj;
} xc;
```

struct/union的对齐标准就是按占用字节数最大的成员的字节数的整数倍对齐，故sizeof(xc) = (((5 + 1) + 8) + 2) + 4 = 20，选D。

3. 字符编码

[Question 1](https://www.nowcoder.com/questionTerminal/cd143d9138cc434eae3e395ace08b0b4)

一个汉字在UTF-8编码下占用1-3个字节，在UTF-16编码下占用2个字节，如果保存为文本文件，还需要加上标识，其中EF BB BF表示使用UTF-8编码，占用3个字节，FE FF表示使用UTF-16编码，占用2个字节，故选BD。

## C/C++

1. const

[Question 1](https://www.nowcoder.com/questionTerminal/557b67decf6540a8ba85ef1f02406bfd)

const对象只能调用const成员函数，故选B。

[Question 2](https://www.nowcoder.com/questionTerminal/16d6bf307eeb4984b91ad4876e3c40b8)

```cpp
const char *p1 = "hello";
char *const p2 = "world";
```

非常量指针p1指向常量，故A正确，B错误；常量指针p2指向非常量，故D错，应注意到"world"存储在常量区，不可修改，故C错。

[Question 3](https://www.nowcoder.com/questionTerminal/949330b7213b45afbadc980591774085)

指针常量表示指针本身是一个常量，常量指针表示指针指向一个常量。

[Question 4](https://www.nowcoder.com/questionTerminal/fa504edf41554be39b616ab5315aa617)

非常量引用必须为左值，故A错误，选A。

2. [static](https://www.nowcoder.com/questionTerminal/e3ea7a08df454558bee00fa1c99d73fe)

func1修改的是静态全局变量，func2修改的是局部变量，func3修改的是静态局部变量，故选B。

3. [char](https://www.nowcoder.com/questionTerminal/3327439779e146dc9035b0977d9469eb)

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

4. [short](https://www.nowcoder.com/questionTerminal/b7dd8b9cf69e4554912a45bdae9a8bda)

```cpp
short si = -32767;
unsigned short usi = si;
```

si的原码为1111 1111 1111 1111，反码为1000 0000 0000 0000，补码为1000 0000 0000 0001，usi的补码也为1000 0000 0000 0001，1从符号位转换为数值位，故选D。

|   |MIN|MAX|
|---|---|---|
| short | -32768 | 32767 |
|unsigned short|0| 65535 |

5. operator priority

[Question 1](https://www.nowcoder.com/questionTerminal/58769985d07646368f73e53a10c862f9)

选D。

[Question 2](https://www.nowcoder.com/questionTerminal/3567b8a580b74315bd2a463c7d686d6d)

选B。

[Question 3](https://www.nowcoder.com/questionTerminal/ea662448f3f043d1a165ae31e647dae3)

选C。

++（后置递增） <--- ++（前置递增） <--- ! <--- &（取地址） <--- % <--- + <--- <= <--- == <--- != <--- &（逻辑与） <--- && <--- || <--- ? :

6. operator overload

[Question 1](https://www.nowcoder.com/questionTerminal/7609a03a292a472ba69008e92785fcbc)

本题选ABC，不能被重载的运算符如下：

+ ::
+ .*
+ .
+ ? :

[Question 2](https://www.nowcoder.com/questionTerminal/569d8c14cc2f4d4dbee54f3652335477)

能作为函数重载的依据是：const、参数类型和参数个数，故选ABC。

7. [Array](https://www.nowcoder.com/questionTerminal/0959b5b04e7842adb74ddf071c3fa52f)

```cpp
int m[][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
```

定义二维数组时可以省略第一维的大小，故选A。

8. Function

[Question 1](https://www.nowcoder.com/questionTerminal/9fd169364f4a42599aa7ade7f1c9bbd9)

func自右向左将参数压入堆栈，故v1为2，v2为0，选D。

[Question 2](https://www.nowcoder.com/questionTerminal/5ecb2abb0a1f4a4b8ad7a1d4abe2d80d)

形参只有函数被调用时才分配存储单元，故选A。

[Question 3](https://www.nowcoder.com/questionTerminal/17d4c9b1a03e4650be5e29af3f2e1f7c)

```cpp
template <class T>
T fun(T x, T y) {
    return x * x + y * y;
}
```

模板函数要求参数类型匹配，否则需要显式指定参数类型，进行类型转换，故B错，选B。

[Question 4](https://www.nowcoder.com/questionTerminal/0dc754158944469b959135ea3e1fdeb0)

```cpp
CSomething a();
```

应注意这里声明了一个名为a的函数，没有创建对象，故选E。

9. Libraries

[Question 1](https://www.nowcoder.com/questionTerminal/316082aaacfe4c3f8faf004e3e0fcf6d)

```cpp
int main() {
    int a; float b, c;
    scanf("%2d%3f%4f", &a, &b, &c);
    printf("\na=%d,b=%d,c=%f", a, b, c);
}
```

printf将参数自右向左依次压入堆栈，其中a是4个字节，b和c被提升为double类型，是8个字节。随后依次出栈，a打印4个字节，读取到的是98；而b打印4个字节，在小端存储方式下，低地址低位，高地址高位，栈顶至栈底为地址增长的方向，故b读取到的是0；c打印8个字节，后4个字节并不是0，但因太小而被忽略，读取到的也是0，故选B。

[Question 2](https://www.nowcoder.com/questionTerminal/f9c598c5fb684411a393621fd4e63b1d)

```cpp
main() {
    char s[] = "123", *p;
    p = s;
    printf("%c%c%c\n", *p++, *p++, *p++);
}
```

printf自右向左计算表达式，故选B。

[Question 3](https://www.nowcoder.com/questionTerminal/33ab3cecf0fb4504998d0dd314de0628)

对于fopen函数，r+模式允许读写，在文件不存在时会报错；w+模式也允许读写，在文件不存在时会创建文件。

10. Process/Thread

[Question 1](https://www.nowcoder.com/questionTerminal/e59625958f3f475ebc6655bdd1dcdc50)

```cpp
void foo() {
    ++a;
    printf("%d", a);
}
```

++a并不是原子操作，其步骤可分为3步：从内存读取a的值到寄存器、+1、将a的值从寄存器回写到内存。故ABCD均有可能。

[Question 2](https://www.nowcoder.com/questionTerminal/1f6cc9c0ef354f86b1727c6c030a1a19)

```cpp
int main() {
    for (int i = 0; i < 2; ++i) {
        fork();
        printf("-");
    }
    return 0;
}
```

如果是printf("-")，子进程会继承父进程的缓冲区，父进程和3个fork子进程各输出2个'-'，共8个；如果是printf("-\n")，缓冲区会被刷新，父进程和第一个fork子进程输出2个'-'，后两个fork子进程输出1个'-'，共6个，故选D。

[Question 3](https://www.nowcoder.com/questionTerminal/0d5acd7276324a6981d696fbe88f817e)

```cpp
int main() {
    int pid;
    int num = 1;
    pid = fork();
    if (pid > 0) {
        ++num;
        printf("in parent: num:%d addr:%x\n", num, &num);
    } else if (pid == 0) {
        printf("in child: num:%d addr:%x\n", num, &num);
    }
}
```

子进程对父进程的数据进行读操作时，是与父进程共享地址空间的，若进行写操作，将发生虚拟地址的拷贝，但物理地址还是一样的，故在父子进程中，num的值不同，num的地址相同，故选B。

[Question 4](https://www.nowcoder.com/questionTerminal/fa5ae81202804fecad9d3b5dc09c3424)

```cpp
int main() {
    printf("Hello");
    fork();
    printf("Hello");
}
```

缓冲区未刷新，故父子进程各输出2次，总共输出4次，选C。

11. Class

[Question 1](https://www.nowcoder.com/questionTerminal/45bb35c18c434829af740c0d843fcb1e)

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

[Question 2](https://www.nowcoder.com/questionTerminal/9ca9a4991164463b90b6ba0fef227030)

若类的析构函数是私有的，编译器将不会在栈空间上为类对象分配空间，这意味着不能直接创建对象，故选B。

[Question 3](https://www.nowcoder.com/questionTerminal/2a49c4d64fa6452ca8ccdbae9172c646)

空类所占的字节数为1，故选B。

[Question 4](https://www.nowcoder.com/questionTerminal/efeff39629c148828732a04641160fde)

类模板是类的模板，模板类是类模板实例化后的类。

[Question 5](https://www.nowcoder.com/questionTerminal/da5c9884bc824b72a345c8fdfb53b79b)

const成员、引用成员和带有引用成员的类成员需要类内初始化，故选A。

12. OOP

[Question 1](https://www.nowcoder.com/questionTerminal/9fb6068728734b6e854335f8bf893a3b)

func的参数不是指针，不存在虚函数的动态绑定，故直接调用B0::display，选A。

[Question 2](https://www.nowcoder.com/questionTerminal/4d04e379d0ba4c74b627a37d19d62a08)

类的构造顺序是从基类到派生类，在基类的构造函数中调用虚函数时尚未构造派生类，并不会呈现出多态，故A错；类的析构顺序是从派生类到基类，在基类的析构函数中调用虚函数时派生类已被析构掉，也不会呈现出多态，故B错，选CD。

[Question 3](https://www.nowcoder.com/questionTerminal/2b9efbd31b4c4f35b086ac9c21fe21f5)

含有纯虚函数的类被称为抽象类，不能被实例化，故A对；基类被虚继承才是虚基类，故B错；C不完整，忽略；纯虚函数也可以有函数体，但必须在类的外部定义，故D错，选A。

[Question 4](https://www.nowcoder.com/questionTerminal/05ac9639c3df4c3aaba673c053efb50b)

struct的默认继承方式为public继承，class的默认继承方式为private继承。

13. [inline](https://www.nowcoder.com/questionTerminal/b592a5037f254806b42278154214bc50)

内联函数不能包含复杂的语句，如switch和while等，故C的说法错误，选C。

14. Details

[Question 1](https://www.nowcoder.com/questionTerminal/553f59e30d9f4d949bc39ad6761026b8)

条件n = 0为假，返回0，故循环一次也不进行，选A。

[Question 2](https://www.nowcoder.com/questionTerminal/8685c71cf8dd49c2a239f978fd387232)

在switch...case表达式中，case后随的表达式必须是整型常量，且default总是最后再执行，故CD错，选AB。

[Question 3](https://www.nowcoder.com/questionTerminal/32e1804df44d48b699e4b7b7e9d97cf7)

```cpp
#ifdef __cplusplus
extern "C" {
#endif
// function declaration
#ifdef __cplusplus
}
#endif
```

extern "C"是为了解决C++代码调用C代码的问题。

[Question 4](https://www.nowcoder.com/questionTerminal/2f17b0526a6d4c5ea8e8e092da70e1cd)

```cpp
void main() {
    int a = -32769;
    printf("%8U\n", a);
}
```

下面给出补码：

||符号位|数值位|
|---|---|---|
|+32769|0|1000 0000 0000 0001|
|-32769|1|0111 1111 1111 1111|
|+32767|0|0111 1111 1111 1111|

若控制字符不符合格式，printf将原样输出，若为"%8u"，printf将输出32767，故选B。

## Computer Network

1. Protocol

[Question 1](https://www.nowcoder.com/questionTerminal/bfac7c49f8cb404fbc1e66fe583c7f92)

中继器处于物理层。

[Question 2](https://www.nowcoder.com/questionTerminal/4af96389f35f4564804c6b7a6ebc0e86)

在不同自治系统AS之间的路由选择不能使用内部网关协议如RIP或OSPF，只能使用边界网关协议BGP，故B的说法错误，选B。

2. Details

[Question 1](https://www.nowcoder.com/questionTerminal/b5083535166747bda6ac4a17357641fe)

当通往目的主机的其他路由不存在时，主机通过默认路由将数据传输到本地网络之外的主机。

3. TCP

[Question 1](https://www.nowcoder.com/questionTerminal/0becf1efabdb4f6585ef9c7bc02f5bef)

TCP的确认号是期望收到对方下一个报文段的第一个数据字节的序号，如主机B正确收到了A发送过来的一个报文段，其序号字段值是38，数据长度是40字节，则B期望收到A的下一个数据序号是78，即确认号是78。

4. HTTP

[Question 1](https://www.nowcoder.com/questionTerminal/4093b5dc1d94447288b5560a5a7717b0)

HTTP状态码302表示临时重定向，故浏览器共发起2次HTTP请求。

[Question 2](https://www.nowcoder.com/questionTerminal/ce9fd3b69f8d4c09a40fc298d9fb65f5)

HTTP/2支持以下新特性：

+ 头部压缩（Header Compression）
+ 多路复用（Multiplexing）
+ 服务端推送（Server Push）
