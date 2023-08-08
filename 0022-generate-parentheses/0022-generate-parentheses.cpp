class Solution {
private:
    void solve(vector<string> &res, int n, int izq, int der, string s) {
        if (s.size() == 2*n) {
            res.push_back(s);
            return;
        }
        
        if (izq < n) {
            string next = s;
            next.push_back('(');
            solve(res, n, izq+1, der, next);
        }
        
        if (izq > der) {
            string next = s;
            next.push_back(')');
            solve(res, n, izq, der+1, next);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(res, n, 0, 0, "");
        return res;
    }
};