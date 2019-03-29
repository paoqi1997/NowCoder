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

#### 2. [反转链表](https://www.nowcoder.com/questionTerminal/75e878df47f24fdc9dc3e400ec6058ca)

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
