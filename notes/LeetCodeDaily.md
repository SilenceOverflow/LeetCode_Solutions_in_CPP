I use this blog to summary main ideas for some LeetCode problems and record frequent bugs.

# Feb.
--------
## 02-19
### 367. Valid Perfect Square
- binary search
- http://www.cnblogs.com/grandyang/p/5619296.html

### 633. Sum of Square Numbers
- sol1. brute force, helper func is isValidSquare, search from 1~num/2, no sqrt()
- sol2. use sqrt()
- sol3. web sol3

### 598. Range Addition II
- by self, easy to pass
- take care: when ops is NULL, should return m*n
- sol2. priority_queue, interesting

### 370. Range Addition
- by self, easy to pass, brute force
- sol2. web sol1. avoid using nested for-loop, only use a single for loop

--------
## 02-20
### 263
### 264
### 313
### 205

--------
## 02-21
### 290.

### 291.
- a complex idea
- remerber to m.erase(c) when helper() returned false;
- sol2. using set to avoid traverse hash table
- thoughts: need to understand the key idea of backtracking


### 728. Self Dividing Numbers
- by self, easy to pass

### 507. Perfect Number
- by self, easy to pass
- take care to cover corner case, i*i
- improvement on saving time, when sum > num




------------------
# Mar.
--------
## 03-21  
### 201. Bitwise AND of Numbers Range [M]
- need to observe that the final result is the common left part of all the consecutive number in the range

### 532. K-diff Pairs in an Array [E]
- sol1: hashmap, but a bit complex to consider 3 cases separately
- sol2: concise hashmap style
- sol3: after look at tags including *two pointers*, http://www.cnblogs.com/grandyang/p/6545075.html

### 530. Minimum Absolute Difference in BST [E]
- sol1: DFS, but without using the BST property
- sol2: inorder traversal, note that we should record the pre node, (// note that root->val always > pre)

### 653. Two Sum IV - Input is a BST [E]
- The most important thing is that for two sum problems, you should first come up with unordered_set/map (insert and search). That's a straight forward idea!
- sol1: using unordered_set/map

### 671. Second Minimum Node In a Binary Tree
- sol1: brute-force, using two integers to record the minimum and the second minimum number
- sol3: web sol3, easy to understand, an intuitive recursion without helper function

--------
## 03-22  
### 669. Trim a Binary Search Tree [E]
- should understand the BST's propety, to decide the pipeline
- sol1. recursive
- sol2. iterative

### 575. Distribute Candies [E]
- easy, no twice, 
- min(n/2, kinds of candies)

### 58. Length of Last Word [E]
- easy, no twice, refer
- just watch for the space on the front and back positions of the input string

### 453. Minimum Moves to Equal Array Elements [E]
- easy, no twice, refer
- but need to change your perspective from n-1 numbers adding 1 to 1 number subtracting 1.

--------
## 03-23
### 462. Minimum Moves to Equal Array Elements II [M]
- easy, no twice,
- note that all need to do is find the median, and sum

### 543. Diameter of Binary Tree [E]
- easy, but refer, could re-do
- convert the problem into obtaining the sum of left and right sub-tree depth

### 346. Moving Average from Data Stream [E]
- easy, no twice,

### 415. Add Strings [E]
- easy, but care about conversion between char and integer
- '0' + integer = integer, so should use char('0' + integer) to obatin a char.

### 696. Count Binary Substrings [E]
- sol1. something like brute-force to examine each bit of the whole string, Time Limit Exceeded 
- sol2. a smart converting original problem to counting numbers of '0's and '1's, update the current number of '0' (or '1') when scaning a new '0' (or '1') from the string, and only count if number of existing '1' (or '0') is larger than '0' (or '1')

 
--------
## 03-24
### 682. Baseball Game [E]
- easy, no twice,
- should come up with using `stack`

### 81. Search in Rotated Sorted Array II [M]
- compared to #33. Search in Rotated Sorted Array, the duplicate values would influence the decision on which side to search
- a trick is that if `nums[left] = nums[mid] = nums[right]`, `right--` till the condition not holds

### 766. Toeplitz Matrix [E]
- easy, no twice,

### 422. Valid Word Square [E]
- easy, no twice,
- just be careful about two border conditions

### 56. Merge Intervals [M]
- after first merge, you should merge all new generated intervals
- sol1. sort the structure, and merge from the largest `start` to the least one. After sorting, it's easy to judge the relationship between between each two consecutive intervals
- sol2. sort start, end vector, and judge when the invervals are not overlapped, and insert to the result vector. Must analyze and understanding what the sorting operation means

### 252. Meeting Rooms [E]
- easy, a sub-problem of #56. Merge Intervals

### 253. Meeting Rooms II [M]
- re-do, should understand it's connection and difference to #56. Merge Intervals and # 252. Meeting Rooms
- should understand how the starting time and ending time influence the conference room after sorting 

```C++
for (int i = 0; i < intervals.size(); i++) {
    if (starts[i] < ends[endpos])
        res++;
    else
        endpos++;
}
```


--------
## 03-25
### 6. ZigZag Conversion [M]
- idea is easy
- [Learn Point] but should care about the border condition `midpos < n`, i.e., remember that each time you calculate a new position, you should check if it exceeds the string length!

### 452. Minimum Number of Arrows to Burst Balloons [M]
- idea is straight-forward, to find non-overlapping group of intervals
- similar to #56. Merge Intervals, # 252. Meeting Rooms, and #253. Meeting Rooms II
- sol1. back-to-front, [Learn Point] lack a break inside inner loop after updating iterator `i`
- sol2. front-to-back

### 435. Non-overlapping Intervals [M]
- idea is straight-forward, to find non-overlapping group of intervals
- re-do, should understand it's connection and difference to #56. Merge Intervals, #252. Meeting Rooms, #253. Meeting Rooms II and #452. Minimum Number of Arrows to Burst Balloons
- [Learn Point] should consider duplicate intervals 

### 796. Rotate String
- easy, no twice
- idea is straight-forward, search for the A[0] in B, split A, B into 2 parts and compare equal length part, respectively



--------
## 03-26
### 11. Container With Most Water [M]
- sol1. brute-force solution using two for-loops, O(n^2), but time limit exceeded
- sol2. "Start by evaluating the widest container, using the first and the last line. All other possible containers are less wide, so to hold more water, they need to be higher. Thus, after evaluating that widest container, skip lines at both ends that don’t support a higher height. Then evaluate that new container we arrived at. Repeat until there are no more possible containers left." Refer to: https://leetcode.com/problems/container-with-most-water/discuss/6090/Simple-and-fast-C++C-with-explanation.

### 42. Trapping Rain Water [H]
- the main idea is find the left and right border for each block
- sol1. DP: search two times of all height vector to build two dp vectors to store the left and right maximum height w.r.t. the current index i, and take the minmum one of those two maxima - the current height to update the final result 
- sol2. Two Pointers: each iteration move the minimum of unit height pointed by left ptr and right ptr, if find lower units during moving then calculate the collected rain
- sol3. Stack: a bit complex, note that for each height[i], we push index into the stack, not the height itself

### 407. Trapping Rain Water II [H]
- a trick (to some extent) idea using priority queue and BFS, could re-do  
- the priority_queue initialized from the border blocks and search for all neighbours of each element in the priority_queue (from small to large) 

### 755. Pour Water [M]




--------
## 03-27
### 693. Binary Number with Alternating Bits [E]
- easy, no twice
- some other tricks, refer to http://www.cnblogs.com/grandyang/p/7696387.html

### 806. Number of Lines To Write String [E]
- easy, no twice

### 293. Flip Game [E]
- easy, no twice

### 294. Flip Game [M]
- backtracking, a bit trick
- sol1. regular way to replace "++"
- sol2. using `find` function to determine the "++" position


--------
## 03-28
### 762. Prime Number of Set Bits in Binary Representation [E]
- easy, no twice
- the only thing need to notice is the prime numbers are limited under 32

### 784. Letter Case Permutation [E]
- backtracking, could re-do  
- should understand the essence of backtracking here -- build parallel routes to compute results

### 57. Insert Interval [H]
- easy, idea is straight-forward

### 654. Maximum Binary Tree [M]
- easy, no twice
- idea is straight-forward using recursion



--------
## 03-29
### 46. Permutations [M]
- backtracking, could re-do 
- no duplicate
- should understand the essence of backtracking here -- build parallel routes to output each element of the num vector, and finish task of each routine separately
- sol2. Swap: a nice idea
- sol2 and sol3, refer to: http://www.cnblogs.com/grandyang/p/4358848.html

### 47. Permutations II [M]
- backtracking, could re-do
- exist duplicates, return all possible unique permutations.
- sol1. using set and convert to vector before return, others are like what did in 46.
- sol2. how to avoid duplicates in results: sort the input array first, then before generating a new route, we should judge whether the former element (if = the current one) is visited. If visited, then could update output. If not, skip and continue. Through this mechanism to kill the duplicates (half of all permutations). 
- for sol1 and sol2, you can draw a process graph to visulize the order of each updated output vector.

### 



--------
## 03-30
### 788. Rotated Digits [E]
- sol1. brute-force, O(N^2)
- sol2. dp, should refer to leetcode discuss, not implement


--------
## 03-31
### 804. Unique Morse Code Words [E]
- sol1. brute-force, O(N^2)

### 


--------
## 04-11 (by 04-12)
### 31. Next Permutation [M]
- sol1. brute-force, but Time Limit Exceeded if the input is like [6,7,5,3,5,6,2,9,1,2,7,0,9]
- sol2. a tricky but concise solution - backword and find the decreasing border n[i], exchange n[i] and the first number bigger than n[i], then sort the elements on the right of n[i]. refer to: http://www.cnblogs.com/grandyang/p/4428207.html

### 60. Permutation Sequence [M]
- sol1. brute-force, but Time Limit Exceeded if the input is like 9, 331987
- sol2. a tricky but concise solution - refer to: http://www.cnblogs.com/grandyang/p/4358678.html

### 78. Subsets [M]
- sol1. bit manipulation
- sol2. Recursion: similar to backtracking in permutations
- sol3. Non-recursion: add a [] vector in vector<vector<int>> res, and for each number in nums[], add it to each element in the current res in order.

### 90. Subsets II [M]
- sol1. 78.sol3 + set
- sol2. 78.sol2 + if current res=[part1,part2] and part1 + nums[j] = part2, only add nums[j] to part2, i.e., begin from the end of part1 to perform
- sol3. 78.sol3 + `while (nums[i] == nums[i+1]) ++i;` to skip duplicate sets. 

--------
## 04-12
### 243. Shortest Word Distance [E]
- sol1. use hashmap to store indices of two words, and search for the min distance
- sol2. refer to: fastest O(n) solution in the submission 

### 244. Shortest Word Distance II [M]
- sol1. same as 243 O(MN), which is suitable for a large input array and being called multiple times.
- sol2. same as 243, but Time Limit Exceeded here due to being called repeatedly. It's suiable for being called only once. 
- sol3. sol1 could be refined to O(M+N), use a while loop with i,j ptr and move the small index to the next one

### 245. Shortest Word Distance III [M]
- sol1. idea is straight-forward. if word1=word2, just search in m[word1]

### 605. Can Place Flowers [E]
- sol1. easy, no twice


--------
## 04-13
### 77. Combinations [M]
- sol1. similar to non-duplicate permutations, but changes two lines `int temp = out.empty()? 0 : out.back(); if (i > temp)` to make sure that each time the added number must larger than the last one in the output vector
- sol2. equivalent to sol1, but modify one line `combineDFS(n, k, **level+1**, out, res);` to `combineDFS(n, k, **i+1**, out, res);`. The former one is the conventional term in permutations.
- sol3. another trick way: http://www.cnblogs.com/grandyang/p/4332522.html

### 39. Combination Sum [M] 
- could reuse
- sol1. similar to 77. and 46., but be careful about the sort operation on `out. If directly sort on out, it may cause the error in `out.pop_back();`.
- sol2. a better way is sort `candidates` at the beginning, and every new route starts from the current index `i`. 

### 40. Combination Sum II [M]
- could not reuse, i.e., each number in C may only be used once in the combination.
- sol1. similar to 39. sol2. if could not reuse, we should set the `start = i+1` each time, compared with `start = i` in the case allowing reuse.

### 216. Combination Sum III [M]
- sol1. similar to the above 40., care about two points: `start = i+1` and `if (out.size() == k && n == 0)`

### 377. Combination Sum IV [M]
- Note that different sequences are counted as different combinations. It's the difference from 39.
- sol1. backtracking but Time Limit Exceeded. One thing to conclude here is 
	- if number could be reused and the order matters, set `start = start`, i.e., each time search from the first element of the nums vector
	- if number could be reused and the order does not matter, set `start = i`, i.e., next round search from the current one and no former numbers could be used
	- if number could not be reused, set `start = i+1` in the helper function
- sol2. DP: `dp[0] = 1` which means that when target is in the nums vector, cnt++; otherwise, `dp[target] = dp[1 + new_target (= taraget - 1)] + dp[2 + new_target (= taraget - 2)] + ...` --> `dp[i] += dp[i-X]`, X is in the nums vector
- follow up:  if negative numbers are allowed in the given array? - https://leetcode.com/problems/combination-sum-iv/discuss/85038/JAVA:-follow-up-using-recursion-and-memorization.

--------
## 04-14
### 378. Kth Smallest Element in a Sorted Matrix [M]
- no hard
- sol1. N ptr. Each time extract current value from each row, and find the minmum one, and increment the index in that row. When k shrinks to 0, stop and find the last number. 
- sol2. priority_queue.
- sol3. binary search

### 755. Pour Water [M]
- sol1. a very concise solution, refer to: http://www.cnblogs.com/grandyang/p/8460541.html
- If left one is no less than current one, just move left. Then, if right one is equal to current one, move right to achieve the minmum one clostest to index K.
- for right of K, the same as left.

### 48. Rotate Image [M]
- easy, no twice

### 581. Shortest Unsorted Continuous Subarray [E]
- sol1. build another vector and sort it, then compare it with the given one to find the borders
- sol2. a better solution: the given vector could be divided into 3 parts `[l:ascending, m:misordered, r:ascending]`. The minmum of `[m+r]` should be larger than the maximum of `l`. Similarly, the maximum of `[l+m]` should be less than the minimum of `r`.


### 228. Summary Ranges [M]
- easy, no twice

### 163. Missing Ranges [M]
- need to care about overflow issues and duplicate cases, especially multiple INT_MIN and INT_MAX

### 54. Spiral Matrix [M]
- easy, no twice
- split to four parts and set the terminate condition

### 650. 2 Keys Keyboard [M]
- sol1. first guess: dp + prime or not (can relax to divide by each number less than it)
- sol2. recursion
- sol3. O(n), best and concise solution


------------------------------
--------
## 04-17
### 50. Pow(x, n) [M]
- care about the negative n cases
- sol1. reduce the problem to half size each iteration
- sol2. recursion 

### 

### 

### 

------------------------
TO DO:

### 5. Longest Palindromic Substring [M]
- interesting dp ideas, re-do
- 

### 4. Median of Two Sorted Arrays [H]
- sol1. very concise but a bit hard to understand, refer to: https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/very-concise-ologminmn-iterative-solution-with-detailed-explanation
- sol2. 

### 401. Binary Watch [E]
224. Basic Calculator

### 786. K-th Smallest Prime Fraction [H]
- sol1. 
