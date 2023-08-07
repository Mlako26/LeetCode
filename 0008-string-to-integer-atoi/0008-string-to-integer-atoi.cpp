class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        bool neg = false;
        long res = 0;
            
        // WhiteSpaces
        while (s[i] == ' ') i++;
        
        // Sign
        if (s[i] == '-') {
            neg = true;
            i++;
        } else if (s[i] == '+') i++;
        
        // Digits Input
        while (i < n && 48 <= s[i] && s[i] <= 57) {
            res = res * 10 + int(s[i]) - 48;
            if (res > INT_MAX || (neg && (-1) * res < INT_MIN)) {
                return neg ? INT_MIN : INT_MAX;
            }
            i++;
        }
        
        if (neg) res *= -1;
        return int(res);
    }
};