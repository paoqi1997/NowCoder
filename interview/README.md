# Interview of NowCoder

面试部分。

## Algorithms and Data Structures

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

利用头插法反转链表。

```cpp
ListNode* reverseList(ListNode *pHead) {
    ListNode *p = pHead;
    ListNode *head = nullptr;
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
