class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            string aux = {};
            for (int j = 0; j < strs[i].size() && j < res.size(); j++) {
                if (res[j] != strs[i][j]) {
                    break;
                }
                aux += res[j];
            }
            res = aux;
        }
        return res;
    }
};