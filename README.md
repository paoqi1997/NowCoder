# NowCoder

个人整理的知识笔记及习题技巧（C/C++后端方向）。

## Computer Basis

### 1. 原码、反码及补码

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

### 2. 字节对齐

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

### 3. 字符编码

[Question 1](https://www.nowcoder.com/questionTerminal/cd143d9138cc434eae3e395ace08b0b4)

一个汉字在UTF-8编码下占用1-3个字节，在UTF-16编码下占用2个字节，如果保存为文本文件，还需要加上标识，其中EF BB BF表示使用UTF-8编码，占用3个字节，FE FF表示使用UTF-16编码，占用2个字节，故选BD。

## C/C++

### 1. const

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

### 2. static

[Question 1](https://www.nowcoder.com/questionTerminal/e3ea7a08df454558bee00fa1c99d73fe)

func1修改的是静态全局变量，func2修改的是局部变量，func3修改的是静态局部变量，故选B。

### 3. char

[Question 1](https://www.nowcoder.com/questionTerminal/3327439779e146dc9035b0977d9469eb)

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

### 4. short

[Question 1](https://www.nowcoder.com/questionTerminal/b7dd8b9cf69e4554912a45bdae9a8bda)

```cpp
short si = -32767;
unsigned short usi = si;
```

si的原码为1111 1111 1111 1111，反码为1000 0000 0000 0000，补码为1000 0000 0000 0001，usi的补码也为1000 0000 0000 0001，1从符号位转换为数值位，故选D。

|   |MIN|MAX|
|---|---|---|
| short | -32768 | 32767 |
|unsigned short|0| 65535 |

### 5. operator priority

[Question 1](https://www.nowcoder.com/questionTerminal/58769985d07646368f73e53a10c862f9)

选D。

[Question 2](https://www.nowcoder.com/questionTerminal/3567b8a580b74315bd2a463c7d686d6d)

选B。

[Question 3](https://www.nowcoder.com/questionTerminal/ea662448f3f043d1a165ae31e647dae3)

选C。

++（后置递增） <--- ++（前置递增） <--- ! <--- &（取地址） <--- % <--- + <--- <= <--- == <--- != <--- &（逻辑与） <--- && <--- || <--- ? :

### 6. operator overload

[Question 1](https://www.nowcoder.com/questionTerminal/7609a03a292a472ba69008e92785fcbc)

本题选ABC，不能被重载的运算符如下：

+ ::
+ .*
+ .
+ ? :

[Question 2](https://www.nowcoder.com/questionTerminal/569d8c14cc2f4d4dbee54f3652335477)

能作为函数重载的依据是：const、参数类型和参数个数，故选ABC。

### 7. Array

[Question 1](https://www.nowcoder.com/questionTerminal/0959b5b04e7842adb74ddf071c3fa52f)

```cpp
int m[][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
```

定义二维数组时可以省略第一维的大小，故选A。

### 8. Function

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

### 9. Libraries

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

### 10. Process/Thread

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

### 11. Class

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

### 12. OOP

[Question 1](https://www.nowcoder.com/questionTerminal/9fb6068728734b6e854335f8bf893a3b)

func的参数不是指针，不存在虚函数的动态绑定，故直接调用B0::display，选A。

[Question 2](https://www.nowcoder.com/questionTerminal/4d04e379d0ba4c74b627a37d19d62a08)

类的构造顺序是从基类到派生类，在基类的构造函数中调用虚函数时尚未构造派生类，并不会呈现出多态，故A错；类的析构顺序是从派生类到基类，在基类的析构函数中调用虚函数时派生类已被析构掉，也不会呈现出多态，故B错，选CD。

[Question 3](https://www.nowcoder.com/questionTerminal/2b9efbd31b4c4f35b086ac9c21fe21f5)

含有纯虚函数的类被称为抽象类，不能被实例化，故A对；基类被虚继承才是虚基类，故B错；C不完整，忽略；纯虚函数也可以有函数体，但必须在类的外部定义，故D错，选A。

[Question 4](https://www.nowcoder.com/questionTerminal/05ac9639c3df4c3aaba673c053efb50b)

struct的默认继承方式为public继承，class的默认继承方式为private继承。

### 13. inline

[Question 1](https://www.nowcoder.com/questionTerminal/b592a5037f254806b42278154214bc50)

内联函数不能包含复杂的语句，如switch和while等，故C的说法错误，选C。

### 14. Details

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

### 1. Protocol

[Question 1](https://www.nowcoder.com/questionTerminal/bfac7c49f8cb404fbc1e66fe583c7f92)

中继器处于物理层。

[Question 2](https://www.nowcoder.com/questionTerminal/4af96389f35f4564804c6b7a6ebc0e86)

在不同自治系统AS之间的路由选择不能使用内部网关协议如RIP或OSPF，只能使用边界网关协议BGP，故B的说法错误，选B。

[Question 3](https://www.nowcoder.com/questionTerminal/da1a839bed4049d3b5f52d6cf5473b2c)

FTP的数据端口是20，控制端口是21。

[Question 4](https://www.nowcoder.com/questionTerminal/c52beaf1c64e4c5f9e9398111a826336)

RIP协议要求网络中的每一个路由器都要维护从它自己到其他每一个目的网络的距离记录，这里的距离也称为跳数，故选A。

[Question 5](https://www.nowcoder.com/questionTerminal/13e71af093014130a945c60b87b02986)

IPv4首部的前一部分的长度是固定的，共20字节，后一部分是可选字段，长度可变；IPv6首部的长度是固定的，共40字节。

[Question 6](https://www.nowcoder.com/questionTerminal/955dad936ed4443bb3705d27e0ac23af)

TFTP使用UDP作为传输层协议。

[Question 7](https://www.nowcoder.com/questionTerminal/6579a864619c48beb7792ea9608e569e)

||FTP|TELNET|SMTP|DNS|
|---|---|---|---|---|
|端口号|21|23|25|53|

### 2. Details

[Question 1](https://www.nowcoder.com/questionTerminal/b5083535166747bda6ac4a17357641fe)

当通往目的主机的其他路由不存在时，主机通过默认路由将数据传输到本地网络之外的主机。

[Question 2](https://www.nowcoder.com/questionTerminal/0a31c5d35cea4ac8834c9aa9cfdd7c8a)

A类地址的默认子网掩码为255.0.0.0，B类为255.255.0.0，C类为255.255.255.0。

[Question 3](https://www.nowcoder.com/questionTerminal/fd3fb9401149463b9732a15911cb7085)

B类地址190.168.0.0在子网掩码255.255.224.0下可以划分8个子网，故选A。

[Question 4](https://www.nowcoder.com/questionTerminal/3145b393b3984c939cf06660f1e5541c)

10.1.0.1/17的广播地址是10.1.127.255。

[Question 5](https://www.nowcoder.com/questionTerminal/3b182e976d424253bc1c33d46e7cab93)

子网掩码最长为30位，即255.255.255.252。

[Question 6](https://www.nowcoder.com/questionTerminal/74c743bd93d549b19a137d52a8f0929e)

10.1.193.0 <-> 10.1.1100 0001.0
10.1.194.0 <-> 10.1.1100 0010.0
10.1.196.0 <-> 10.1.1100 0100.0
10.1.198.0 <-> 10.1.1100 0110.0

路由聚合后应为10.1.192.0/21(8+8+5)

[Question 7](https://www.nowcoder.com/questionTerminal/fb2527f7ab8c4627a7b0acd692f50432)

255.255.255.255为本地广播地址。

### 3. TCP

[Question 1](https://www.nowcoder.com/questionTerminal/0becf1efabdb4f6585ef9c7bc02f5bef)

TCP的确认号是期望收到对方下一个报文段的第一个数据字节的序号，如主机B正确收到了A发送过来的一个报文段，其序号字段值是38，数据长度是40字节，则B期望收到A的下一个数据序号是78，即确认号是78。

[Question 2](https://www.nowcoder.com/questionTerminal/f9c633e61a70412abc308b6bbf0dc08b)

TIME_WAIT出现在主动关闭的一方，CLOSE_WAIT出现在被动关闭的一方，故A的说法错误，选A。

[Question 3](https://www.nowcoder.com/questionTerminal/6962b10958c1413a80972995a4e08d6b)

accept发生在三次握手后。

[Question 4](https://www.nowcoder.com/questionTerminal/b930c3f10bbb407ca2c8c19496e9c656)

以下是一个典型TCP客户端会经历的状态序列：SYN_SENT -> ESTABLISHED -> FIN_WAIT_1 -> FIN_WAIT_2 -> TIME_WAIT

[Question 5](https://www.nowcoder.com/questionTerminal/cee6014573f841e2b1b19fbd89ab5d32)

在基于窗口的拥塞控制中，发送方让自己的发送窗口等于拥塞窗口。

由题，拥塞窗口cwnd的变化过程如下：1 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> (11) -> (12)

超时后调整门限值ssthresh = cwnd / 2 = 4，同时设置拥塞窗口cwnd = 1，进入慢开始阶段。

过程 1 -> 2 -> 4 执行慢开始算法，cwnd = ssthresh后改用拥塞避免算法，最终cwnd = 10，故选A。

发送方的窗口的上限值应当取接收窗口rwnd和拥塞窗口cwnd这两个变量中较小的一个。

[Question 6](https://www.nowcoder.com/questionTerminal/2d5a65326a4c43ffa87ca7bf5ad1a632)

在TCP的三次握手中，服务端从来不进入SYN_SENT状态，故A错；服务端收到客户端的ACK包后进入ESTABLISHED状态，故B错；如果服务端没有收到客户端的ACK包，服务端便知道客户端并没有要求建立连接，也不存在关闭连接这一说，故D错，选C。

[Question 7](https://www.nowcoder.com/questionTerminal/a7c0a2d163ee48e7a1ffd447744daae9)

对于连续ARQ协议来说，接收方不必对收到的分组逐个发送确认，而是在收到几个分组后，对按序到达的最后一个分组发送确认，这就是说，到这个分组为止的所有分组都已正确收到了，故需要重传的帧为4、5、6、7，帧数为4，故选A。

### 4. HTTP

[Question 1](https://www.nowcoder.com/questionTerminal/4093b5dc1d94447288b5560a5a7717b0)

HTTP状态码302表示临时重定向，故浏览器共发起2次HTTP请求。

[Question 2](https://www.nowcoder.com/questionTerminal/ce9fd3b69f8d4c09a40fc298d9fb65f5)

HTTP/2支持以下新特性：

+ 头部压缩（Header Compression）
+ 多路复用（Multiplexing）
+ 服务端推送（Server Push）

[Question 3](https://www.nowcoder.com/questionTerminal/1a499276f5e74da08e54eb9e125a42f3)

cache-control是HTTP/1.1才有的。

## Operating System

### 1. CPU

[Question 1](https://www.nowcoder.com/questionTerminal/683d207653d9460ba9b60418695f2c8d)

P5: CPU(20ms) -> IO1(30ms) -> CPU(10ms) -> IO2(15ms)
P1: IO2(10ms) -> CPU(10ms) -> IO1(30ms) -> CPU(10ms)
P3: IO1(30ms) -> CPU(10ms) -> IO2(30ms) -> CPU(10ms)

### 2. Memory

[Question 1](https://www.nowcoder.com/questionTerminal/eea7506591b045cc85a122e1b44ec3a1)

Belady现象指的是在使用先进先出（FIFO）算法作为缺页置换算法时，分配的页面数增多但缺页率反而提高的异常现象。

[Question 2](https://www.nowcoder.com/questionTerminal/195013bc3ae14f1d9b75e0d1e750326a)

虚拟内存的最大容量为计算机字长和内存容量与外存容量之和的最小值。

[Question 3](https://www.nowcoder.com/questionTerminal/4c8e40890a3141adbebeaa4cce4ee1a7)

LRU算法为最近最少使用算法。

在2路组相联映射方式下，主存地址为0-1、4-5、8-9的映射到第0组，主存地址为2-3、6-7的映射到第1组。

||0|4|8|2|0|6|8|6|4|8|
|---|---|---|---|---|---|---|---|---|---|---|
|块0（第0组）| 0 | 0 | 8 | 8 | 8 | 8 | 8(Y) | 8 | 8 | 8(Y) |
|块1（第0组）|   | 4 | 4 | 4 | 0 | 0 | 0 | 0 | 4 | 4 |
|块2（第1组）|   |   |   | 2 | 2 | 2 | 2 | 2 | 2 | 2 |
|块3（第1组）|   |   |   |   |   | 6 | 6 | 6(Y) | 6 | 6 |

### 3. File

[Question 1](https://www.nowcoder.com/questionTerminal/727d7b5a1ff84880a9fef115a99ee1b0)

系统文件不是Linux文件系统中的文件类型。

[Question 2](https://www.nowcoder.com/questionTerminal/a402b258a18b4a408567648bf3d8f9f2)

文件目录以文件的形式存储。

### 4. Process/Thread

[Question 1](https://www.nowcoder.com/questionTerminal/49106f40d10c429cb33a5e4f38d50b5d)

临界区是指进程访问临界资源的那段代码，故说法不正确，选B。

[Question 2](https://www.nowcoder.com/questionTerminal/6432b302f7ca41db963e1adbba6287c1)

```cpp
#include <stdio.h>
#include <unistd.h>
int main() {
    fork(); // 2个进程
    fork(); // 4个进程
    fork(); // 8个进程
    printf("hello\n");
    return 0;
}
```

[Question 3](https://www.nowcoder.com/questionTerminal/5f6d704427424a1cb30eeb56af5d5b1f)

锁可分为递归锁和非递归锁，其中递归锁称为可重入锁，非递归锁称为不可重入锁。

同一个线程多次获取同一个递归锁，不会产生死锁；同一个线程多次获取同一个非递归锁，会产生死锁。

Windows下的互斥量（Mutex）和临界区（Critical Section）是可递归的，Linux下的互斥量（pthread_mutex_t）默认是非递归的，但可以通过设置属性将其设置为递归的。

[Question 4](https://www.nowcoder.com/questionTerminal/c6126fd5ba2d40b0bfca35439a6c3563)

java.lang.Object和java.util.concurrent.locks.Condition。

[Question 5](https://www.nowcoder.com/questionTerminal/9d99bf2509934c2e8758c9427a0cb189)

n * (w - 1) + 1 <= m

[Question 6](https://www.nowcoder.com/questionTerminal/76258178ea9b4b1b8e6234031e79b04a)

死锁发生的四个必要条件是：

1. 互斥条件
2. 请求与保持条件
3. 不可剥夺条件
4. 循环等待条件

我们可以通过破坏条件来预防死锁，但互斥条件不可被破坏。

[Question 7](https://www.nowcoder.com/questionTerminal/705a1fd6af274b5b9507c19095777a48)

最多允许m个进程同时进入互斥段，故信号量为m，此时有n - m个进程阻塞，故信号量为-(n - m) = m - n，选A。

### 5. Details

[Question 1](https://www.nowcoder.com/questionTerminal/22d8540272da40fd827731b30b68fff4)

主存地址寄存器MAR的位数与程序计数器PC的位数相同。

[Question 2](https://www.nowcoder.com/questionTerminal/86327c4dcd9e41488b87f1d04b92a81c)

发生缺页中断后，相关过程如下：分配页框 -> 磁盘I/O -> 修改页表。

[Question 3](https://www.nowcoder.com/questionTerminal/9c29042ca2814e8881870123b8058196)

盘块号 = 32 + 409612 / (1024 * 8) = 32 + 50 = 82，块内字节序号 = 409612 % (1024 * 8) / 8 = 12 / 8 = 1，故选C。
