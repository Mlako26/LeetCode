class Solution {
public:
int solve(vector<vector<int>>& dp, vector<int>& coins, int i, int amount) {
    if (dp[i][amount] != -1) return dp[i][amount];
    if (!amount) return 0;
    if (amount > 0 && i == coins.size()) return INT_MAX;
    if (amount < coins[i]) return solve(dp, coins, i+1, amount);
    int aux1 = solve(dp, coins,i,amount-coins[i]);
    if (aux1 != INT_MAX) aux1++;
    int aux2 = solve(dp, coins,i+1,amount-coins[i]);
    if (aux2 != INT_MAX) aux2++;
    int aux3 = solve(dp, coins, i+1, amount);
    return dp[i][amount] = min(min(aux1,aux2), aux3);
}

int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1,-1));
    int ans = solve(dp, coins, 0, amount);
    return ans == INT_MAX ? -1 : ans;
}
};