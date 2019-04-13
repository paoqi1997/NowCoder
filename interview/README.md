# Interview of NowCoder

面试部分。

## Knowledge

### C++

#### 1. 说下extern关键字？

对于extern变量，在.cpp文件中定义变量，在.h文件中用extern声明该变量，其他文件就可以通过包含该头文件以使用该变量；extern函数同理；对于extern "C"来说，这是为了解决C++代码调用C代码的问题，比方说在.c文件中编写实现代码，在.h文件中添加extern "C"以指示编译器这部分的代码按C语言的方式编译。

#### 2. 说下sizeof和strlen的区别？

```cpp
char s1[] = {'a', 'b'};
cout << sizeof(s1) << ' ' << strlen(s1) << endl; // 2 UB

char s2[] = {'a', 'b', '\0'};
cout << sizeof(s2) << ' ' << strlen(s2) << endl; // 3 2

char s3[] = "ab";
cout << sizeof(s3) << ' ' << strlen(s3) << endl; // 3 2

char *s4 = "ab";
cout << sizeof(s4) << ' ' << strlen(s4) << endl; // 4 2
```

#### 3. 说下有哪些字符串拷贝的方法？strcpy有哪些缺陷？

copy、strcpy、strncpy和memcpy。

dest空间不够大，存在内存访问越界的问题；遇到'\0'拷贝就结束，'\0'作为一个普通字符而不是结束符，存在字符串拷贝不完全的问题；拷贝自身，存在内存重叠的问题。

#### 4. 说下new和malloc的区别？

+ new是C++的，malloc是C的。

+ new和delete配对使用，malloc和free配对使用。

+ new是运算符，malloc是函数。

+ new会调用构造函数，malloc不会。

+ 若申请内存失败，new抛出异常，malloc返回NULL。

+ new会检查类型，malloc只关心申请内存的字节数，不关心类型。

+ new返回时不需要类型转换，malloc需要。

#### 5. 说下new的底层实现？

首先调用operator new，然后调用operator new中的malloc，再调用相应的构造函数。

#### 6. 什么是虚函数？虚函数的作用？

当我们使用基类的指针或引用调用一个虚成员函数时会执行动态绑定，直到运行时才能知道到底调用了哪个版本的函数。基类指针可以通过指向不同的派生类对象以调用对应的虚函数，这里体现的是动态多态。

#### 7. 虚函数表是什么？

每个包含虚函数的类都有一个虚函数表，同一个类的所有对象都使用同一个虚表，虚表是一个指针数组，每个元素对应一个指向虚函数的指针，虚表在编译阶段就已经构造出来，类对象在创建时便拥有一个指向虚表的指针。

```cpp
class A {
public:
    virtual void vfunc1();
    virtual void vfunc2();
private:
    int a;
};
class B : public A {
public:
    virtual void vfunc1();
private:
    int b;
}
```

A的虚表有2个指针，分别指向A::vfunc1和A::vfunc2，B的虚表也有两个指针，但B继承A且重写了vfunc1函数，故其分别指向B::vfunc1和A::vfunc2，也就是说，类对象的虚表指针指向类所属的虚表，虚表中的指针指向其继承关系中最近的某个类的虚函数。

#### 8. 如果基类的析构函数不为虚，会出现什么问题？

若析构函数不为虚，则指向派生类对象的基类指针在delete时无法释放派生类对象，造成内存泄漏。

### Operating System

#### 1. 说下I/O复用？

I/O复用就是构造一个我们感兴趣的描述符列表，然后调用某个函数，直到这些描述符中的某个描述符准备好进行I/O时，该函数才返回。

#### 2. 说下进程间通信的方式？

+ 管道（只能在具有公共祖先的两个进程之间使用）

```cpp
#include <unistd.h>
int pipe(int fd[2]);
```

+ 命名管道（通过FIFO，不相关的进程也能交换数据）

```cpp
#include <sys/stat.h>
int mkfifo(const char *path, mode_t mode);
int mkfifoat(int fd, const char *path, mode_t mode);
```

+ 消息队列

```cpp
#include <sys/msg.h>
int msgget(key_t key, int flag);
int msgctl(int msqid, int cmd, struct msqid_ds *buf);
int msgsnd(int msqid, const void *ptr, size_t nbytes, int flag);
ssize_t msgrcv(int msqid, void *ptr, size_t nbytes, long type, int flag);
```

+ 信号量

```cpp
#include <sys/sem.h>
int semget(key_t key, int nsems, int flag);
int semctl(int semid, int semnum, int cmd, ...);
int semop(int semid, struct sembuf semoparray[], size_t npos);
```

+ 共享内存

```cpp
#include <sys/shm.h>
int shmget(key_t key, size_t size, int flag);
int shmctl(int shmid, int cmd, struct shmid_ds *buf);
void* shmat(int shmid, const void *addr, int flag);
int shmdt(const void *addr);
```

### Computer Network

#### 1. 为什么是三次握手而不是四次或两次？

四次握手的过程如下：

1. 主机A向B发送一个SYN。

2. 主机B向A发送一个ACK。

3. 主机B向A发送一个SYN。

4. 主机A向B发送一个ACK。

这里的2和3可以合并成一个步骤，故三次握手即可。

在三次握手中，第一次握手后，B知道A能发，第二次握手后，A知道B能收和发，第三次握手后，B知道A能收。

两次握手的过程如下：

1. 主机A向B发送一个SYN。

2. 主机B向A发送一个ACK，再发送一个SYN。

如果A向B发送的SYN并没有丢失，而是延误到连接释放后的某个时间才到达B，B在收到这个SYN后，误以为A又发起连接请求，于是向A发送一个ACK，表示同意建立连接。如果没有第三次握手，新的连接就建立了。实际上A并没有发起连接请求，而B却在等待A发送数据，B的资源就这样被浪费了。

如果加入第三次握手，就可以避免上述问题，A不会就B发过来的ACK向B发送ACK，由于B没收到ACK，也就知道A并没有发起连接请求。

### Algorithms and Data Structures

#### 1. 说说什么是哈希表？用在什么场景？

将关键字通过哈希函数映射到一个哈希表的某个位置。

场景：在平均情况下，哈希表的查找、插入与删除的时间复杂度均为O(1)。

#### 2. 发生哈希冲突时该怎么解决？

拉链法：给哈希表的每个桶配置为一个链表。

开地址法：通过某种解决冲突的策略探查下一个空位置，相关策略如下。

    1. 线性探查法：顺序查找下去，直到找到空位置为止。

    2. 伪随机法：利用伪随机数发生器计算下一个探查位置。

    3. 双散列法：第一个哈希函数计算探查位置的初始值，第二个哈希函数计算探查步长。

#### 3. 说下堆排序的原理？

假设为升序排序：

    1. 建立一个大根堆，其中公式为x[i] >= x[2 * i + 1] && x[i] >= x[2 * i + 2]，对于某个根节点，我们先找到值最大的叶子节点，再依此调整根节点与它的位置。

    2. 交换根节点与最后一个叶子节点的值，使末尾值最大，随后重新调整堆。

参考实现如下：

```cpp
void hs(int m[], int rootIndex, int n) {
    int rootVal = m[rootIndex], leafIndex = 2 * rootIndex + 1;
    while (leafIndex < n) {
        if (leafIndex + 1 < n && m[leafIndex] < m[leafIndex + 1]) {
            ++leafIndex;
        }
        if (rootVal < m[leafIndex]) {
            m[rootIndex] = m[leafIndex];
            rootIndex = leafIndex, leafIndex = 2 * rootIndex + 1;
        } else {
            break;
        }
    } m[rootIndex] = rootVal;
}
void heapsort(int m[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        hs(m, i, n);
    }
    for (int i = 1; i < n; ++i) {
        swap(m[0], m[n - i]);
        hs(m, 0, n - i);
    }
}
```

#### 4. 怎么逆序打印链表？

递归的方式如下。

```cpp
template <typename T>
struct ListNode {
    T val;
    ListNode *next;
    ListNode(const T& _val) : val(_val), next(nullptr) {}
};
template <typename T>
void printListFromTailToHead(ListNode<T> *head) {
    if (head != nullptr) {
        printListFromTailToHead(head->next);
        cout << head->val << endl;
    }
}
int main() {
    ListNode<int> *head = new ListNode<int>(1);
    head->next = new ListNode<int>(2);
    printListFromTailToHead(head);
    delete head->next;
    delete head;
    return 0;
}
```

#### 5. 说下快速排序的原理？怎么利用快排思想找出数组中第k大的数？

假设为升序排序：

    1. 从m中选择m[l]/m[r]作为基准元素，然后设置两个哨兵，其索引分别为l和r，在l和r相遇之前，哨兵l对应的值都不大于基准元素，哨兵r对应的值都不小于基准元素，否则交换这两个值，随后返回l/r作为分治区间的边界索引。

    2. 将[left, index - 1]记为左段，将[index + 1, right]记为右段，对左段及右段进行递归快速排序。

参考实现如下：

```cpp
int qs(int m[], int l, int r) {
    int tmpVal = m[l];
    while (l < r) {
        while (l < r && m[l] < tmpVal) {
            ++l;
        }
        while (l < r && tmpVal < m[r]) {
            --r;
        }
        swap(m[l], m[r]);
    }
    return r;
}
void quicksort(int m[], int left, int right) {
    if (left < right) {
        int index = qs(m, left, right);
        quicksort(m, left, index - 1);
        quicksort(m, index + 1, right);
    }
}
```

稍作修改即可利用快排思想找出数组中第k大的数。

```cpp
int fkm(int m[], int l, int r) {
    int tmpVal = m[l];
    while (l < r) {
        while (l < r && m[l] > tmpVal) {
            ++l;
        }
        while (l < r && tmpVal > m[r]) {
            --r;
        }
        swap(m[l], m[r]);
    }
    return r;
}
int find_k_max(int m[], int left, int right, int k) {
    if (left < right) {
        int index = fkm(m, left, right);
        if (k - 1 == index) {
            return m[k - 1];
        } else if (k - 1 < index) {
            find_k_max(m, left, index - 1, k);
        } else {
            find_k_max(m, index + 1, right, k);
        }
    }
}
```

## Code

### Array

#### 1. [二维数组中的查找](https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e)

从左下角开始寻找，若target < array[row][col]，则在上方，若target > array[row][col]，则在右方。

```cpp
bool Find(int target, vector<vector<int>> array) {
    int row = array.size() - 1;
    size_t col = 0;
    while (row >= 0 && col < array[0].size()) {
        if (target == array[row][col]) {
            return true;
        } else if (target < array[row][col]) {
            --row;
        } else {
            ++col;
        }
    } return false;
}
```

#### 2. [旋转数组的最小数字](https://www.nowcoder.com/questionTerminal/9f3231a991af4f55b95579b44b7a01ba)

二分查找。

```cpp
int minNumberInRotateArray(vector<int> rotateArray) {
    int low = 0, high = rotateArray.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        // [2, 3, 4, 5, 6]
        // 最小数字在mid的左边
        if (rotateArray[mid] < rotateArray[high]) {
            high = mid;
        }
        // [4, 5, 6, 2, 3]
        // 最小数字在mid的右边
        else if (rotateArray[mid] > rotateArray[high]) {
            low = mid + 1;
        }
        // [1, 0, 1, 1, 1] | [1, 1, 1, 0, 1]
        // 不确定
        else {
            ++low;
        }
    } return rotateArray[low];
}
```

#### 3. [调整数组顺序使奇数位于偶数前面](https://www.nowcoder.com/questionTerminal/beb5aa231adc45b2a5dcc5b62c93f593)

略。

```cpp
void reOrderArray(vector<int>& array) {
    stable_sort(array.begin(), array.end(), [](int x, int y){
        return x % 2 && !(y % 2);
    });
}
```

#### 4. [顺时针打印矩阵](https://www.nowcoder.com/questionTerminal/9b4c81a02cd34f76be2659fa0d54342a)

略。

```cpp
vector<int> printMatrix(vector<vector<int>> matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> vec;
    int circle = (min(row, col) + 1) / 2;
    for (int i = 0; i < circle; ++i) {
        // 上方
        for (int _col = i; _col < col - i; ++_col) {
            vec.push_back(matrix[i][_col]);
        }
        // 右方
        for (int _row = i + 1; _row < row - i; ++_row) {
            vec.push_back(matrix[_row][col - i - 1]);
        }
        if (i < row - i - 1) {
            // 下方
            for (int _col = col - i - 2; _col >= i; --_col) {
                vec.push_back(matrix[row - i - 1][_col]);
            }
        }
        if (i < col - i - 1) {
            // 左方
            for (int _row = row - i - 2; _row >= i + 1; --_row) {
                vec.push_back(matrix[_row][i]);
            }
        }
    } return vec;
}
```

### String

#### 1. [替换空格](https://www.nowcoder.com/questionTerminal/4060ac7e3e404ad1a894ef3e17650423)

略。

```cpp
void replaceSpace(char *str, int length) {
    int i = 0, len = length;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            ++i;
        } else {
            for (int j = len; j > i; --j) {
                str[j + 2] = str[j];
            }
            str[i] = '%', str[i + 1] = '2', str[i + 2] = '0';
            len += 2;
        }
    }
}
```

#### 2. [字符串的排列](https://www.nowcoder.com/questionTerminal/fe6b651b66ae47d7acce78ffdd9a96c7)

递归。

```cpp
void implPermutation(vector<string>& box, string s, int index) {
    if (index == s.length() - 1) {
        if (find(box.begin(), box.end(), s) == box.end()) {
            box.push_back(s);
        }
    } else {
        for (size_t i = index; i < s.length(); ++i) {
            swap(s[index], s[i]);
            implPermutation(box, s, index + 1);
            swap(s[index], s[i]);
        }
    }
}
vector<string> Permutation(string s) {
    vector<string> box;
    if (!s.empty()) {
        implPermutation(box, s, 0);
        sort(box.begin(), box.end());
    }
    return box;
}
```

### Linked List

#### 1. [从尾到头打印链表](https://www.nowcoder.com/questionTerminal/d0267f7f55b3412ba93bd35cfa8e8035)

略。

```cpp
vector<int> printListFromTailToHead(ListNode *head) {
    ListNode *p = head;
    vector<int> vec;
    while (p != nullptr) {
        vec.push_back(p->val);
        p = p->next;
    }
    reverse(vec.begin(), vec.end());
    return vec;
}
```

#### 2. [链表中倒数第k个结点](https://www.nowcoder.com/questionTerminal/529d3ae5a407492994ad2a246518148a)

快慢指针。

```cpp
ListNode* FindKthToTail(ListNode *pListHead, unsigned int k) {
    if (pListHead == nullptr || k == 0) {
        return nullptr;
    }
    ListNode *p = pListHead, *q = pListHead;
    for (int i = 1; i < k; ++i) {
        if (p->next != nullptr) {
            p = p->next;
        } else {
            return nullptr;
        }
    }
    while (p->next != nullptr) {
        p = p->next;
        q = q->next;
    }
    return q;
}
```

#### 3. [反转链表](https://www.nowcoder.com/questionTerminal/75e878df47f24fdc9dc3e400ec6058ca)

头插法。

```cpp
ListNode* ReverseList(ListNode *pHead) {
    ListNode *p = pHead, *head = nullptr;
    // head <- p <- q
    while (p != nullptr) {
        ListNode *q = p->next;
        p->next = head;
        head = p;
        p = q;
    }
    return head;
}
```

#### 4. [合并两个排序的链表](https://www.nowcoder.com/questionTerminal/d8b6b4358f774294a89de2a6ac4d9337)

递归。

```cpp
ListNode* Merge(ListNode *pHead1, ListNode *pHead2) {
    if (pHead1 == nullptr) {
        return pHead2;
    }
    if (pHead2 == nullptr) {
       return pHead1;
    }
    if (pHead1->val <= pHead2->val) {
        //  pHead1  -> (pHead1->next) -> ...
        // (pHead2) -> ...
        pHead1->next = Merge(pHead1->next, pHead2);
        return pHead1;
    } else {
        // (pHead1) -> ...
        //  pHead2  -> (pHead2->next) -> ...
        pHead2->next = Merge(pHead1, pHead2->next);
        return pHead2;
    } 
}
```

#### 5. [复杂链表的复制](https://www.nowcoder.com/questionTerminal/f836b2c43afc4b35ad6adc41ec941dba)

略。

```cpp
RandomListNode* Clone(RandomListNode *pHead) {
    if (pHead == nullptr) {
        return pHead;
    } else {
        auto p = pHead;
        while (p) {
            // 复制节点并将新的节点链接到原来的节点的后面
            // p -> pp
            // p -> cloneNode -> pp
            auto pp = p->next;
            auto cloneNode = new RandomListNode(p->label);
            p->next = cloneNode;
            cloneNode->next = pp;
            p = pp;
        }
        p = pHead;
        while (p) {
            // 为新的节点设置random
            // p ---> p->next ---> p->next->next
            if (p->random) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        p = pHead;
        auto head = pHead->next;
        while (p) {
            // 拆分链表
            // p ---> p->next(cloneNode) ---> cloneNode->next
            auto cloneNode = p->next;
            p->next = cloneNode->next;
            if (cloneNode->next) {
                cloneNode->next = cloneNode->next->next;
            }
            p = p->next;
        }
        return head;
    }
}
```

### Stack & Queue

#### 1. [用两个栈实现队列](https://www.nowcoder.com/questionTerminal/54275ddae22f475981afa2244dd448c6)

stack1作为入队列，stack2作为出队列。

```cpp
stack<int> stack1, stack2;
void push(int node) {
    stack1.push(node);
}
int pop() {
    int node;
    if (stack2.empty()) {
        while (!stack1.empty()) {
            node = stack1.top();
            stack1.pop();
            stack2.push(node);
        }
    }
    node = stack2.top();
    stack2.pop();
    return node;
}
```

#### 2. [包含min函数的栈](https://www.nowcoder.com/questionTerminal/4c776177d2c04c2494f2555c9fcc1e49)

引入stack2作为监视最小值的栈。

```cpp
class Solution {
public:
    void push(int value) {
        stack1.push(value);
        if (stack2.empty() || stack1.top() < stack2.top()) {
            stack2.push(value);
        }
    }
    void pop() {
        if (stack1.top() == stack2.top()) {
            stack2.pop();
        }
        stack1.pop();
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return stack2.top();
    }
private:
    stack<int> stack1, stack2;
};
```

#### 3. [栈的压入、弹出序列](https://www.nowcoder.com/questionTerminal/d77d11405cc7470d82554cb392585106)

给入栈序列和出栈序列设置两个哨兵，其索引分别为i和j，然后设置一个辅助栈s。

在一次操作中，辅助栈从入栈序列中取走哨兵i对应的值并将其压栈，随后栈顶元素与出栈序列中哨兵j对应的值进行比较，如果相等，则应出栈，同时哨兵j前进，否则哨兵i前进，继续压栈。

如果最后辅助栈为空，则出栈序列是入栈序列对应的一个弹出序列，否则不是。

```cpp
// pushV -> 1 2 3 4 5
//  popV -> 4 5 3 2 1 (true)
//       -> 4 3 5 1 2 (false)
bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    if (pushV.empty()) {
        return false;
    }
    stack<int> s;
    for (size_t i = 0, j = 0; i < pushV.size(); ++i) {
        s.push(pushV[i]);
        while (!s.empty() && s.top() == popV[j]) {
            s.pop();
            ++j;
        }
    } return s.empty();
}
```

### Binary Tree

#### 1. [重建二叉树](https://www.nowcoder.com/questionTerminal/8a19cbe657394eeaac2f6ea9b0f6fcf6)

查找根节点并递归地构建左右子树。

```cpp
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
    if (pre.empty()) {
        return nullptr;
    }
    TreeNode *root = new TreeNode(pre[0]);
    int rootindex = 0, length = in.size();
    // 查找当前根节点
    for (int i = 0; i < length; ++i) {
        if (in[i] == pre[0]) {
            rootindex = i;
            break;
        }
    }
    vector<int> left_pre, left_in, right_pre, right_in;
    // 构建左子树
    for (int i = 0; i < rootindex; ++i) {
        left_pre.push_back(pre[i + 1]);
        left_in.push_back(in[i]);
    }
    // 构建右子树
    for (int i = rootindex + 1; i < length; ++i) {
        right_pre.push_back(pre[i]);
        right_in.push_back(in[i]);
    }
    // 递归构建左右节点
    root->left = reConstructBinaryTree(left_pre, left_in);
    root->right = reConstructBinaryTree(right_pre, right_in);
    return root;
}
```

#### 2. [树的子结构](https://www.nowcoder.com/questionTerminal/6e196c44c7004d15b1610b9afca8bd88)

递归。

```cpp
bool isBinA(TreeNode *pRootA, TreeNode *pRootB) {
    if (pRootB == nullptr) {
        return true;
    }
    if (pRootA == nullptr) {
        return false;
    }
    if (pRootA->val == pRootB->val) {
        return isBinA(pRootA->left, pRootB->left) && isBinA(pRootA->right, pRootB->right);
    } else {
        return false;
    }
}
bool HasSubtree(TreeNode *pRootA, TreeNode *pRootB) {
    bool flag = false;
    if (pRootA != nullptr && pRootB != nullptr) {
        flag = isBinA(pRootA, pRootB);
        if (!flag) {
            flag = HasSubtree(pRootA->left, pRootB);
        }
        if (!flag) {
            flag = HasSubtree(pRootA->right, pRootB);
        }
    } return flag;
}
```

#### 3. [二叉树的镜像](https://www.nowcoder.com/questionTerminal/564f4c26aa584921bc75623e48ca3011)

递归。

```cpp
void Mirror(TreeNode *pRoot) {
    if (pRoot) {
        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
}
```

#### 4. [从上往下打印二叉树](https://www.nowcoder.com/questionTerminal/7fe2212963db4790b57431d9ed259701)

层次遍历。

```cpp
vector<int> PrintFromTopToBottom(TreeNode *root) {
    vector<int> pool;
    queue<TreeNode*> nodes;
    while (root) {
        pool.push_back(root->val);
        if (root->left) {
            nodes.push(root->left);
        }
        if (root->right) {
            nodes.push(root->right);
        }
        if (nodes.empty()) {
            break;
        } else {
            root = nodes.front();
            nodes.pop();
        }
    } return pool;
}
```

#### 5. [二叉搜索树的后序遍历序列](https://www.nowcoder.com/questionTerminal/a861533d45854474ac791d90e447bafd)

对于二叉搜索树的后序遍历序列来说，最后一个元素对应于根节点，前面的元素分为两部分，第一部分的元素均小于根节点，第二部分的元素均大于根节点。

```cpp
bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.empty()) {
        return false;
    } else {
        int rootIndex = sequence.size() - 1;
        while (rootIndex) {
            int i = 0;
            while (sequence[i] < sequence[rootIndex]) ++i;
            while (sequence[i] > sequence[rootIndex]) ++i;
            if (i == rootIndex) {
                --rootIndex;
            } else {
                return false;
            }
        } return true;
    }
}
```

#### 6. [二叉树中和为某一值的路径](https://www.nowcoder.com/questionTerminal/b736e784e3e34731af99065031301bca)

深搜。

```cpp
void dfs(TreeNode *root, int expectNumber, vector<vector<int>>& box, vector<int>& path) {
    path.push_back(root->val);
    if (!root->left && !root->right) {
        if (root->val == expectNumber) {
            box.push_back(path);
        }
    }
    if (root->left) {
        dfs(root->left, expectNumber - root->val, box, path);
    }
    if (root->right) {
        dfs(root->right, expectNumber - root->val, box, path);
    }
    // 回溯
    path.pop_back();
}
vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
    vector<vector<int>> box;
    vector<int> path;
    if (root) {
        dfs(root, expectNumber, box, path);
    }
    return box;
}
```

#### 7. [二叉搜索树与双向链表](https://www.nowcoder.com/questionTerminal/947f6eb80d944a84850b0538bf0ec3a5)

递归。

```cpp
void implConvert(TreeNode*& prev, TreeNode *curr) {
    if (curr) {
        // inorder(p->left);
        // ...
        // inorder(p->right);
        implConvert(prev, curr->left);
        if (prev) {
            prev->right = curr;
        }
        curr->left = prev;
        // 修改prev本身
        prev = curr;
        implConvert(prev, curr->right);
    }
}
TreeNode* Convert(TreeNode *pRootOfTree) {
    if (pRootOfTree == nullptr) {
        return nullptr;
    } else {
        TreeNode *prev = nullptr;
        implConvert(prev, pRootOfTree);
        TreeNode *head = pRootOfTree;
        while (head->left) {
            head = head->left;
        }
        return head;
    }
}
```

### Recursion

#### 1. [斐波那契数列](https://www.nowcoder.com/questionTerminal/c6c7742f5ba7442aada113136ddea0c3)

略。

```cpp
int Fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        int n1 = 0, n2 = 1, n3;
        for (int i = 2; i <= n; ++i) {
            n3 = n1 + n2;
            n1 = n2, n2 = n3;
        }
        return n3;
    }
}
```

#### 2. [跳台阶](https://www.nowcoder.com/questionTerminal/8c82a5b80378478f9484d87d1c5f12a4)

略。

```cpp
int jumpFloor(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        return jumpFloor(n - 1) + jumpFloor(n - 2);
    }
}
```

#### 3. [变态跳台阶](https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387)

略。

```cpp
int jumpFloorII(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            cnt += jumpFloorII(n - i);
        }
        return cnt;
    }
}
```

#### 4. [矩形覆盖](https://www.nowcoder.com/questionTerminal/72a5a919508a4251859fb2cfb987a0e6)

与跳台阶原理相同，1级台阶对应1个2 * 1的小矩形，2级台阶对应2个2 * 1的小矩形，n级台阶对应n个2 * 1的小矩形，也就是1个2 * n的大矩形。

```cpp
int rectCover(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        return rectCover(n - 1) + rectCover(n - 2);
    }
}
```

### Details

#### 1. [二进制中1的个数](https://www.nowcoder.com/questionTerminal/8ee967e43c2c4ec193b040ea7fbb10b8)

略。

```cpp
int NumberOf1(int n) {
    if (true) {
        int cnt = 0;
        while (n) {
            // 15
            // 1111 & 1110 -> 1110
            // 1110 & 1101 -> 1100
            // 1100 & 1011 -> 1000
            // 1000 & 0111 -> 0000
            n &= n - 1;
            ++cnt;
        }
        return cnt;
    } else {
        return bitset<32>(n).count();
    }
}
```

#### 2. [数值的整数次方](https://www.nowcoder.com/questionTerminal/1a834e5e3e1a4b7ba251417554e07c00)

略。

```cpp
double Power(double base, int exp) {
    return pow(base, exp);
}
```
