class Solution {
public:
int solve(vector<vector<int>>& dp, string s, vector<string>& wordDict, int i) {
    if (dp[s.size()][i] != -1) return dp[s.size()][i];
    if (!s.size()) return true;
    if (i == wordDict.size()) return false;
    bool ans = solve(dp, s, wordDict, i+1);
    if (wordDict[i] == s.substr(0, wordDict[i].size())) ans |= solve(dp, s.substr(wordDict[i].size()), wordDict, 0);
    return dp[s.size()][i] = ans;
}

bool wordBreak(string s, vector<string>& wordDict) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(wordDict.size() + 1, -1));
    return solve(dp, s, wordDict, 0);    
}
};