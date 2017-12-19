# 078. Subsets

## Description
Given a set of **distinct** integers, nums, return all possible subsets (the power set).

**Note**: The solution set must not contain duplicate subsets.

For example,
If _**nums**_ = `[1,2,3]`, a solution is:

```
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```

## Solving Ideas
- 首先，给定 `n` 个元素的集合，其子集元素个数为 `2^n`;
- 其次，集合中每个元素`是/否`在某个子集中可以用 `1/0` 比特来表示；
- 借助Bit Manipulation的特性，检验 `0` 到 `2^n-1` 的每一个二进制位，即可实现。


## Solutions

```c++
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res(pow(2, nums.size()), vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < pow(2, nums.size()); j++) {
                if ( (j >> i) & 1 ) {
                    res[j].push_back(nums[i]);
                }
            }
        }
        return res;
    }
};
```

## Complexity
|  Time  | Space  |
|:-----: | :-----:|
| O(n * 2^n) | O(1) |


## Thinking


