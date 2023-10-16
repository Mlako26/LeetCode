class Solution {
public:
    int solve(vector<int>& dp, string& s, int i) {
        int n = s.size();
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        
        int ans = solve(dp, s, i+1);
        
        for (int j = 1; j <= n - i; j++) {
            string t = s.substr(i, j);
            int l = 0, r = j - 1;
            bool pal = true;
            while (l < r) {
                if (t[l++] != t[r--]) pal = false;
            }
            if (pal) ans++;
        }
        
        return dp[i] = ans;
    }
    
    int countSubstrings(string s) {
        vector<int> dp(s.size() + 1, -1);
        return solve(dp, s, 0);
    }
};