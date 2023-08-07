class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        
        if (n == 0) return {};
        
        for (auto c : letters[int(digits[0]) - 48 - 2]) {
            string aux = "";
            aux.push_back(c);
            res.push_back(aux);
        }
        
        for (int i = 1; i < n; i++) {
            vector<string> aux;
            for (auto c : letters[int(digits[i]) - 48 - 2]) {
                for (auto s : res) {
                    string next = s;
                    next.push_back(c);
                    aux.push_back(next);
                }
            }
            res = aux;
        }
        
        return res;
    }      
};