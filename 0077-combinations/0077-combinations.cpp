class Solution {
public:
    void solve(vector<vector<int>>& res, vector<int>& s, int n, int k, int i) {
        if (s.size() == k) {
            res.push_back(s);
            return;
        }
        
        if (s.size() + (n - i + 1) < k) return;
        
        while (i <= n) {
            s.push_back(i);
            solve(res, s, n, k, i+1);
            s.pop_back();
            i++;
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> s;
        solve(res, s, n, k, 1);
        return res;
    }
};