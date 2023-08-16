class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        
        for (int x : nums) {
            int n = res.size();
            for (int i = 0; i < n; i++) {
                res.push_back(res[i]);
                res.back().push_back(x);
            }
        }
        
        return res;
    }
};