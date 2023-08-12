class Solution {
private:
    void solve(vector<vector<int>> &res, vector<int>& nums, vector<bool> &used, vector<int> &s, int i) {
        if (i == nums.size()) {
            res.push_back(s);
            return;
        }
        
        for (int j = 0; j < nums.size(); j++) {
            if (!used[j]) {
                s.push_back(nums[j]);
                used[j] = true;
                solve(res, nums, used, s, i+1);
                s.pop_back();
                used[j] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        vector<int> s; s.reserve(nums.size());
        solve(res, nums, used, s, 0);
        return res;
    }
};