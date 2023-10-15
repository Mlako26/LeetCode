class Solution {
public:
    int solve(vector<int>& dp, vector<int>& nums, int i) {
        int n = nums.size();
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        
        return dp[i] = max(solve(dp, nums, i+1), nums[i] + solve(dp, nums, i+2));
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return solve(dp, nums, 0);
    }
};