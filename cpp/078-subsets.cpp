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



