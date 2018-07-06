## Binary Tree Traversal/二叉树遍历
主要有层序，前序，中序，后序：
- 144. Binary Tree Preorder Traversal [M]
- 94. Binary Tree Inorder Traversal [M]
- 145. Binary Tree Postorder Traversal [M]
- 102. Binary Tree Level Order Traversal [M]  
- 107. Binary Tree Level Order Traversal II [E] 
- 103. Binary Tree Zigzag Level Order Traversal [M]
- 314. Binary Tree Vertical Order Traversal [M]

一般来说有三种遍历方法：递归，非递归（stack+iterative），Morris遍历。递归写法，相对较为容易；非递归写法相对较难。其中，中序遍历的非递归写法最简单，后序遍历最难。

前两种是O(n)的空间复杂度，第三种是O(1)的空间复杂度。要使用O(1)空间进行遍历，最大的难点在于，遍历到子节点的时候怎样重新返回到父节点（假设节点中没有指向父节点的p指针），由于不能用栈作为辅助空间。为了解决这个问题，Morris方法用到了线索二叉树（threaded binary tree）的概念。在Morris方法中不需要为每个节点额外分配指针指向其前驱（predecessor）和后继节点（successor），只需要利用叶子节点中的左右空指针指向某种顺序遍历下的前驱节点或后继节点就可以了。

先来讨论前序，中序，后序遍历，最后来看层序。

### Preorder Traversal
Solution 1: Recursion

```
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preorder(root, res);
    return res;
}
void preorder (TreeNode* node, vector<int>& res) {
    if (!node) return;
    res.push_back(node->val);
    preorder(node->left, res);
    preorder(node->right, res);
}
```

Solution 2: Non-Recursion, stack

```
vector<int> preorderTraversal(TreeNode* root) {
    if (!root)  return {};
    vector<int> res;
    stack<TreeNode*> s{{root}};
    while (!s.empty()) {
        TreeNode* temp = s.top();
        s.pop();
        res.push_back(temp->val);
        if (temp->right) s.push(temp->right);
        if (temp->left) s.push(temp->left);
    }
    return res;
}
```

Solution 3: Non-Recursion, stack + a helper node

```
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* p = root;
    while (!s.empty() || p) {
        if (p) {
            s.push(p);
            res.push_back(p->val);
            p = p->left;
        }
        else {
            TreeNode* temp = s.top();
            s.pop();
            p = temp->right;
        }
    }
    return res;
}
```

### Inorder Traversal
Solution 1: Recursion

```
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
}
void inorder(TreeNode* node, vector<int>& res) {
    if (!node)  return;
    inorder(node->left, res);
    res.push_back(node->val);
    inorder(node->right, res);
}
```

Solution 2: Non-Recursion, stack + a helper node

```
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* p = root;
    while (!s.empty() || p) {
        if (p) {
            s.push(p);
            p = p->left;
        }
        else {
            TreeNode* temp = s.top();
            s.pop();
            res.push_back(temp->val);
            p = temp->right;
        }
    }
    return res;
}
```

### Postorder Traversal
Solution 1: Recursion

```
vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
}
void postorder(TreeNode* node, vector<int>& res) {
    if (!node) return;
    postorder(node->left, res);
    postorder(node->right, res);
    res.push_back(node->val);
}
```

Solution 2: Non-Recursion, stack + a helper node

```
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* p = root;
    while (!s.empty() || p) {
        if (p) {
            s.push(p);
            res.insert(res.begin(), p->val);
            p = p ->right;
        }
        else {
            TreeNode* temp = s.top();
            s.pop();
            p = temp->left;
        }
    }
    return res;
}
```


### Level Order Traversal
Solution 1: Recursion, BFS

```
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    levelOrder(root, 0, res);
    return res;
}
void levelOrder(TreeNode* root, int level, vector<vector<int>>& res) {
    if (!root) return;
    if (res.size() == level) res.push_back({});
    
    res[level].push_back(root->val);
    
    levelOrder(root->left, level + 1, res);
    levelOrder(root->right, level + 1, res);
}
```

Solution 2: BFS, queue

```
vector<vector<int>> levelOrder(TreeNode* root) { 
    vector<vector<int>> res;
    if (!root)
        return res;
    
    queue<TreeNode*> n;
    n.push(root);
    
    while (!n.empty()) {
        int size = n.size();
        vector<int> v;
        
        for (int i = 0; i < size; i++) {
            TreeNode* temp = n.front();
            n.pop();
            
            v.push_back(temp->val);
            
            if (temp->left) n.push(temp->left);
            if (temp->right) n.push(temp->right);
        }
        res.push_back(v);
    }   
    return res;
}
```


### references: 
- [[LeetCode] Binary Tree Inorder Traversal 二叉树的中序遍历](http://www.cnblogs.com/grandyang/p/4297300.html)
- [Morris Traversal方法遍历二叉树（非递归，不用栈，O(1)空间）](http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html)
- [leetcode | 二叉树的前序遍历、中序遍历、后续遍历的非递归实现](https://blog.csdn.net/quzhongxin/article/details/46315251)
- [二叉树前序、中序、后序遍历非递归写法的透彻解析](https://blog.csdn.net/zhangxiangdavaid/article/details/37115355)
- [前中后序遍历](https://github.com/CyC2018/Interview-Notebook/blob/master/notes/Leetcode%20%E9%A2%98%E8%A7%A3.md#%E5%89%8D%E4%B8%AD%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86)