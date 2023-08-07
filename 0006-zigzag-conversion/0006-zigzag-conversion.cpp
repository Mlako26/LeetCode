class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int n = s.size(), curRow = 1;
        bool down = true;
        string res = {};
        vector<int> row(n, -1);
        for (int i = 0; i < n; i++) {
            row[i] = curRow;
            if (down) {
                if (curRow == numRows) {
                    down = false;
                    curRow--;
                } else {
                    curRow++;
                }
            } else {
                if (curRow == 1) {
                    down = true;
                    curRow++;
                } else {
                    curRow--;
                }
            }
        }

        for (int i = 1; i <= numRows; i++) {
            for (int j = 0; j < n; j++) {
                if (row[j] == i) res += s[j];
            }
        }
        return res;
    }
};