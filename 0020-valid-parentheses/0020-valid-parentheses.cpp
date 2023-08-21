class Solution {
public:
    bool isValid(string s) {
        vector<char> aux;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') aux.push_back(c);
            else {
                if (!aux.size()) return false;
                if (c == ')' && aux.back() != '(') return false;
                if (c == ']' && aux.back() != '[') return false;
                if (c == '}' && aux.back() != '{') return false;
                aux.pop_back();
            }
        }
        
        return !aux.size();
    }
};