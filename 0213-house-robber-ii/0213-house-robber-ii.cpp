class Solution {
public:
    int solve(vector<int>& dp, vector<int>& nums, bool first, int i) {
        int n = nums.size();
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        if (i == n-1) {
            if (first) return 0;
            else return nums[i];
        }
        return dp[i] = max(solve(dp, nums, first, i+1), nums[i] + solve(dp, nums, first, i+2));
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size()+1, -1), dp2(nums.size()+1, -1);
        return max(solve(dp1, nums, false, 1), nums[0] + solve(dp2, nums, true, 2));
    }
};