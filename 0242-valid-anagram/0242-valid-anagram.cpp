class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> letters;
        if (s.size() != t.size()) return false;
        
        for (char c : s) {
            letters[c]++;
        }
        
        for (char c : t) {
            if (letters.count(c) == 0 || --letters.at(c) == -1) return false;
        }
        
        return true;
    }
};