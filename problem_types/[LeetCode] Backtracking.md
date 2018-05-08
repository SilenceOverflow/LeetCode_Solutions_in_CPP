
Usually, the main idea of the so-called backtraking is to generate parallel routes to output each element of the num vector, and finish task of each routine separately. 


# Permutations
## template 1 - for non-duplicate cases
For the first template, we should build a helper function with 5 elements, including: 
- input number vector, 
- backtracking level, 
- a vector to record each element being visited or not, 
- a updated output vector,
- the final result.

In the helper function, if the current level equals the input vector's size, then add the current output vector to the final result vector. Otherwise, find a non-visited element and generate a new route by call the helper function agagin, then backtrack to the state before generating this new route. This is very important and why the method is called as "backtracking"!


```C++
  	vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;
        vector<bool> visited (nums.size(), false);
        permuteDFS(nums, 0, visited, output, res);
        return res;
    }
    void permuteDFS(vector<int>& nums, int level, vector<bool>&  visited, vector<int>& output, vector<vector<int>>& res) {
        // if (output.size() == nums.size() )
        if (level == nums.size() )
            res.push_back(output);
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    output.push_back(nums[i]);
                    permuteDFS(nums, level+1, visited, output, res);
                    output.pop_back();
                    visited[i] = false;
                }
            }
        }
    }
```

## template 2 - to avoid duplicates

1st idea to use set to store the output vector and transfer to vector. 3 lines are key changes to the template 1.

```
set<vector<int>> res;

return vector<vector<int>> (res.begin(), res.end());

res.insert(output);
```


```C++
	vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        vector<int> output;
        permuteDFS(nums, 0, visited, output, res);
        return vector<vector<int>> (res.begin(), res.end());
    }
    void permuteDFS(vector<int>& nums, int level, vector<bool>& visited, vector<int>& output, set<vector<int>>& res) {
        if (level == nums.size()) 
            res.insert(output);
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    output.push_back(nums[i]);
                    permuteDFS(nums, level+1, visited, output, res);
                    output.pop_back();
                    visited[i] = false;
                }
            }
        }
    }
```

# Subsets 
The following is solution with recursion. There are non-recursive solutions for subsets.

## template 1 - for non-duplicate cases

```C++
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> res;
        vector<int> output;
        sort(nums.begin(), nums.end());
        permuteDFS(nums, 0, output, res);
        return res;
    }
    void permuteDFS(vector<int>& nums, int level, vector<int>& output, vector<vector<int>>& res) {
        // not add
        res.push_back(output);
        // add
            for (int i = level; i < nums.size(); i++) {   
                output.push_back(nums[i]);
                permuteDFS(nums, i+1, output, res);
                output.pop_back();
            }
    }
```

```
						[]        
                   /          \        
                  /            \     
                 /              \
              [1]                []
           /       \           /    \
          /         \         /      \        
       [1 2]       [1]       [2]     []
      /     \     /   \     /   \    / \
  [1 2 3] [1 2] [1 3] [1] [2 3] [2] [3] []
```

## template 2 - for duplicate cases
```C++
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> res;
        vector<int> output;
        sort(nums.begin(), nums.end());
        permuteDFS(nums, 0, output, res);
        return res;
    }
    void permuteDFS(vector<int>& nums, int level, vector<int>& output, vector<vector<int>>& res) {
        // not add
        res.push_back(output);
        // add
            for (int i = level; i < nums.size(); i++) {   
                output.push_back(nums[i]);
                permuteDFS(nums, i+1, output, res);
                output.pop_back();
                while (i + 1 < numsS.size() && nums[i] == nums[i + 1]) ++i;
            }
    }
```


```
						[]        
                   /          \        
                  /            \     
                 /              \
              [1]                []
           /       \           /    \
          /         \         /      \        
       [1 2]       [1]       [2]     []
      /     \     /   \     /   \    / \
  [1 2 2] [1 2]  X   [1]  [2 2] [2] X  []
```

# Combinations
## template 1 - for combination sum, reuse elements
```C++
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> out;
        helper(candidates, target, out, res);
        return vector<vector<int>> (res.begin(), res.end());
    }
    void helper(vector<int>& nums, int target, vector<int>& out, set<vector<int>>& res) {
        if (target == 0) {
            // if directly sort on out, it may cause the error in out.pop_back();
            vector<int> temp = out;
            sort(temp.begin(), temp.end());
            res.insert(temp);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= target) {
                out.push_back(nums[i]);
                helper(nums, target - nums[i], out, res);
                out.pop_back();
            }
        }
    }
```


## template 2 - for combination sum, not reuse elements
```C++
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, out, res);
        return vector<vector<int>> (res.begin(), res.end());
    }
    void helper(vector<int>& nums, int target, int start, vector<int>& out, set<vector<int>>& res) {
        if (target == 0) {
            res.insert(out);
        }
        for (int i = start; i < nums.size(); i++) {
            if (nums[i] <= target) {
                out.push_back(nums[i]);
                helper(nums, target - nums[i], i+1, out, res);
                out.pop_back();
            }
        }
    }
```


# References:
1. https://leetcode.com/problems/combination-sum-iv/discuss/85120/C++-template-for-ALL-Combination-Problem-Set