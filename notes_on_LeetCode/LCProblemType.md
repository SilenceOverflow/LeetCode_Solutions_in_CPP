# LeetCode Problem Type

The topics are arranged in alphabetical order.

<!-- GFM-TOC -->
<!-- * [算法思想](#算法思想)
    * [二分查找](#二分查找)
    * [贪心思想](#贪心思想)
    * [双指针](#双指针)
    * [排序](#排序)
        * [快速选择](#快速选择)
        * [堆排序](#堆排序)
        * [桶排序](#桶排序)
    * [搜索](#搜索)
        * [BFS](#bfs)
        * [DFS](#dfs)
        * [Backtracking](#backtracking)
    * [分治](#分治)
    * [动态规划](#动态规划)
        * [斐波那契数列](#斐波那契数列)
        * [最长递增子序列](#最长递增子序列)
        * [最长公共子序列](#最长公共子序列)
        * [0-1 背包](#0-1-背包)
        * [数组区间](#数组区间)
        * [字符串编辑](#字符串编辑)
        * [分割整数](#分割整数)
        * [矩阵路径](#矩阵路径)
        * [其它问题](#其它问题)
    * [数学](#数学)
        * [素数](#素数)
        * [最大公约数](#最大公约数)
        * [进制转换](#进制转换)
        * [阶乘](#阶乘)
        * [字符串加法减法](#字符串加法减法)
        * [相遇问题](#相遇问题)
        * [多数投票问题](#多数投票问题)
        * [其它](#其它)
* [数据结构相关](#数据结构相关)
    * [栈和队列](#栈和队列)
    * [哈希表](#哈希表)
    * [字符串](#字符串)
    * [数组与矩阵](#数组与矩阵)
    * [链表](#链表)
    * [树](#树)
        * [递归](#递归)
        * [层次遍历](#层次遍历)
        * [前中后序遍历](#前中后序遍历)
        * [BST](#bst)
        * [Trie](#trie)
    * [图](#图)
    * [位运算](#位运算)
* [参考资料](#参考资料) -->
<!-- GFM-TOC -->

--------
## Backtracking
- General references:
	- http://www.cnblogs.com/wuyuegb2312/p/3273337.html
	- https://github.com/CyC2018/Interview-Notebook/blob/master/notes/Leetcode%20%E9%A2%98%E8%A7%A3.md#backtracking

### Combinations
- 77. Combinations    
- 39. Combination Sum I
- 40. Combination Sum II
- 216. Combination Sum III
- 377. Combination Sum IV
- references: 
	- https://leetcode.com/problems/combination-sum-iv/discuss/85120/C++-template-for-ALL-Combination-Problem-Set
	- https://leetcode.com/problems/combination-sum-iv/discuss/85106/A-summary-of-all-combination-sum-problem-in-LC-C++

### Permutations
- 31. Next Permutation
- 46. Permutations
- 47. Permutations II
- 60. Permutation Sequence
- 266. Palindrome Permutation
- 267. Palindrome Permutation II
- 784. Letter Case Permutation

### Subsets
- 78. Subsets    
- 90. Subsets II
- references:
	- https://zhuanlan.zhihu.com/p/34083013?group_id=952032396409843712
	- https://zhuanlan.zhihu.com/p/34153380
	- https://zhuanlan.zhihu.com/p/28340833
	- https://zhuanlan.zhihu.com/p/24523433

### Word Search
- 79. Word Search [M]
- 212. Word Search II [H]


--------
## Binary Search
- 33. Search in Rotated Sorted Array [M]
- 81. Search in Rotated Sorted Array II [M]
- 153. Find Minimum in Rotated Sorted Array [M]
- 154. Find Minimum in Rotated Sorted Array II [H]
- 215. Kth Largest Element in an Array [M]
- 230. Kth Smallest Element in a BST [M]
- 378. Kth Smallest Element in a Sorted Matrix [M]
- 658. Find K Closest Elements [M]
- 744. Find Smallest Letter Greater Than Target [E]

--------
## Binary Tree/BST
### Binary Tree Traversal
- 144. Binary Tree Preorder Traversal [M]
- 94. Binary Tree Inorder Traversal [M]
- 145. Binary Tree Postorder Traversal [M]
- 102. Binary Tree Level Order Traversal [M]  
- 107. Binary Tree Level Order Traversal II [E] 
- 103. Binary Tree Zigzag Level Order Traversal [M]
- 314. Binary Tree Vertical Order Traversal [M]
- references: 
    - [[LeetCode] Binary Tree Inorder Traversal 二叉树的中序遍历](http://www.cnblogs.com/grandyang/p/4297300.html)
    - [Morris Traversal方法遍历二叉树（非递归，不用栈，O(1)空间）](http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html)
    - [leetcode | 二叉树的前序遍历、中序遍历、后续遍历的非递归实现](https://blog.csdn.net/quzhongxin/article/details/46315251)
    - [二叉树前序、中序、后序遍历非递归写法的透彻解析](https://blog.csdn.net/zhangxiangdavaid/article/details/37115355)
    - [前中后序遍历](https://github.com/CyC2018/Interview-Notebook/blob/master/notes/Leetcode%20%E9%A2%98%E8%A7%A3.md#%E5%89%8D%E4%B8%AD%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86)

### Construct Binary Tree
- 105. Construct Binary Tree from Preorder and Inorder Traversal [M]
- 106. Construct Binary Tree from Inorder and Postorder Traversal [M]

### Iterator
- 173. Binary Search Tree Iterator [M]
- 281. Zigzag Iterator [M]
- 284. Peeking Iterator [M]
- 285. Inorder Successor in BST [M]

### Longest Consecutive Sequence
- 298. Binary Tree Longest Consecutive Sequence [M]
- 549. Binary Tree Longest Consecutive Sequence II [M]
- 128. Longest Consecutive Sequence (similar question) [H] 


### 想法
- 处理树的问题，尤其是对BST的操作，如果一开始没有想法或者只能想到brute force，不妨与几种遍历方式联系想想或者是DFS、BFS之类的

--------
## Dynamic Programming
### Best Time to Buy and Sell Stock
- 121. Best Time to Buy and Sell Stock [E]
- 122. Best Time to Buy and Sell Stock II [E]
- 123. Best Time to Buy and Sell Stock III [H]
- 188. Best Time to Buy and Sell Stock IV [H]
- 309. Best Time to Buy and Sell Stock with Cooldown [M]
- 714. Best Time to Buy and Sell Stock with Transaction Fee [M]
- references: [Most consistent ways of dealing with the series of stock problems
](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems)

### Regularization
- 10. Regular Expression Matching [H]
- 44. Wildcard Matching [H]

--------
## Finding Missing/Duplicate Number(s) in Vector
- 数组中找Missing，duplicate呀核心思想就是“环”，时间复杂度O(n)：
- Three Main Methods: +n, -nums[i], relocate elements
- 268. Missing Number [E]
- 442. Find All Duplicates in an Array [M]
- 448. Find All Numbers Disappeared in an Array [E]
- 645. Set Mismatch [E]
- 287. Find the Duplicate Number [M]
- 565. Array Nesting [M]
- 41. First Missing Positive [H]

--------
## Graph
### Course Schedule (Directed graph)
- 207. Course Schedule [M]
- 210. Course Schedule II [H]
- 630. Course Schedule III [H]

### Indirected graph
- 133. Clone Graph [M]

--------
## K Elements 
- 347. Top K Frequent Elements  
- 692. Top K Frequent Words     
- 373. Find K Pairs with Smallest Sums
- 658. Find K Closest Elements 

## Kth Smallest Element 
- 215. Kth Largest Element in an Array    
- 230. Kth Smallest Element in a BST    
- 378. Kth Smallest Element in a Sorted Matrix
- 440. K-th Smallest in Lexicographical Order    
- 668. Kth Smallest Number in Multiplication Table
- 719. Find K-th Smallest Pair Distance
- 786. K-th Smallest Prime Fraction

--------
## Overlapping/Non-Overlapping Intervals
- 56. Merge Intervals 
- 57. Insert Interval
- 252. Meeting Rooms 
- 253. Meeting Rooms II 
- 435. Non-overlapping Intervals 
- 452. Minimum Number of Arrows to Burst Balloons

--------
## String/Stack/Recursion
### Calculator
- 224. Basic Calculator [H]
- 227. Basic Calculator II [M]
- 772. Basic Calculator III [H]
- [ ] 770. Basic Calculator IV [H]

### Palindrome
- 5. Longest Palindromic Substring
- 9. Palindrome Number
- 125. Valid Palindrome
- 680. Valid Palindrome II
- [ ] 131. Palindrome Partitioning  
- [ ] 132. Palindrome Partitioning I 
- [ ] 214. Shortest Palindrome    
- 234. Palindrome Linked List    
- 266. Palindrome Permutation
- [ ] 267. Palindrome Permutation II  
- [ ] 336. Palindrome Pairs    
- [ ] 409. Longest Palindrome    
- 479. Largest Palindrome Product    
- [ ] 564. Find the Closest Palindrome    

### Serialize and Deserialize
- 271. Encode and Decode Strings [M]
- 297. Serialize and Deserialize Binary Tree [H]
- 449. Serialize and Deserialize BST [M]
- 536. Construct Binary Tree from String [M]
- 606. Construct String from Binary Tree [E]

--------
## Tree
### Serialize and Deserialize
- 297. Serialize and Deserialize Binary Tree [H]
- 449. Serialize and Deserialize BST [M]
- 536. Construct Binary Tree from String [M]
- 606. Construct String from Binary Tree [E]

--------
## Trie
- 208. Implement Trie (Prefix Tree) [M]
- 211. Add and Search Word - Data structure design [M]
- 212. Word Search II [H]
- 745. Prefix and Suffix Search [M]

