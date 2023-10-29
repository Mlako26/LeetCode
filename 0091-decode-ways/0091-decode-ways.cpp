class Solution {
public:
    int solve(vector<int>& dp, string s, int i) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];

        dp[i] = solve(dp,s,i+1);
        if (i+1 < s.size() && (int) (s[i] - '0') * 10 + (int) (s[i+1] - '0') <= 26) dp[i] += solve(dp,s,i+2);
        return dp[i];
    }   

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return solve(dp, s, 0);
    }
};