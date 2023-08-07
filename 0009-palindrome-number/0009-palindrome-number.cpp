class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string num = to_string(x);
        string reverse;
        for (int i = num.size() - 1; i >= 0; i--) {
            reverse += num[i];
        }
        return num == reverse;
    }
};