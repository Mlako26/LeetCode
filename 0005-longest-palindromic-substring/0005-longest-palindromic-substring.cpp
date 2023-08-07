class Solution {
private:
    bool solve(vector<vector<int>> &mem, int left, int right, string &s) {     
        if (mem[left][right] != -1) return mem[left][right]; 

        bool res = true;
        res = res && s[left] == s[right];
        if (left + 1 <= right - 1) {
            res = res && solve(mem, left+1, right-1, s);
        }

        return mem[left][right] = res;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, max = 0;
        vector<vector<int>> mem(n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                solve(mem, i, j, s);
                if (mem[i][j] && j-i+1 > max) {
                    max = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, max);
    }
};