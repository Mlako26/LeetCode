class Solution {
private:
    void solve(vector<string> &res, int n, int izq, int der, string &s) {
        if (s.size() == 2*n) {
            res.push_back(s);
            return;
        }
        
        if (izq < n) {
            s.push_back('(');
            solve(res, n, izq+1, der, s);
            s.pop_back();
        }
        
        if (izq > der) {
            s.push_back(')');
            solve(res, n, izq, der+1, s);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        solve(res, n, 0, 0, s);
        return res;
    }
};