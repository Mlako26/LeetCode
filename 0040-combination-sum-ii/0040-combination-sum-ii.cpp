class Solution {
private:
    void solve(vector<vector<int>> &res, vector<int> &candidates, vector<int> &s, int i, int r) {
        if (r == 0) {
            res.push_back(s);
            return;
        }
        
        while (i < candidates.size()) {
            if (r - candidates[i] >= 0) {
                s.push_back(candidates[i]);
                solve(res, candidates, s, i+1, r-candidates[i]);
                s.pop_back();
            }
            while (i < candidates.size() - 1 && candidates[i] == candidates[i+1]) i++;
            i++;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> s;
        sort(candidates.begin(), candidates.end());
        solve(res, candidates, s, 0, target);
        return res;
    }
};