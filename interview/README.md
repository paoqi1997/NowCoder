# Interview of NowCoder

面试部分。

## Algorithms and Data Structures

### 1. Array

[Question 1](https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e)

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

### 2. Linked List

[Question 1](https://www.nowcoder.com/questionTerminal/75e878df47f24fdc9dc3e400ec6058ca)

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

### 3. Binary Tree

[Question 1](https://www.nowcoder.com/questionTerminal/8a19cbe657394eeaac2f6ea9b0f6fcf6)

查找根节点并递归地构建左右子树。

```cpp
TreeNode* reConstructBinaryTree(std::vector<int> pre, std::vector<int> in) {
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
    std::vector<int> left_pre, left_in, right_pre, right_in;
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
