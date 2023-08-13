class Solution {
private:
    void solve(vector<int> &candidates, vector<vector<int>> &res, vector<int> &aux, int i, int sum) {
        if (sum == 0) res.push_back(aux);

        while (i < candidates.size()) {
            if (sum - candidates[i] >= 0) {
                aux.push_back(candidates[i]);
                solve(candidates, res, aux, i, sum - candidates[i]);
                aux.pop_back();
            }
            i++;
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> aux;
        solve(candidates, res, aux, 0, target);
        return res;
    }
};