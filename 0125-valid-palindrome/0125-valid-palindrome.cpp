class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for (char c : s) {
            if (c >= '0' && c <= '9') s1.push_back(c);
            else if (c >= 'a' && c <= 'z') s1.push_back(c);
            else if (c >= 'A' && c <= 'Z') s1.push_back(c + ('a'-'A'));
        }
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        
        return s1 == s2;
    }
};