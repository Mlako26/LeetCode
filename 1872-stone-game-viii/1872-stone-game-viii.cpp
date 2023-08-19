class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<long long> sumas(n);
        sumas[0] = stones[0];
        for(int i = 1; i < n; ++i) sumas[i] = sumas[i-1] + stones[i];

        vector<long long> dp(n, sumas.back()-1);
        dp[n-1] = 0;
        dp[n-2] = sumas.back();
        for(int i = n-3; i >= 0; --i) {
            dp[i] = max(dp[i+1], sumas[i+1] - dp[i+1]);
        }   
        return dp[0];
    }
};