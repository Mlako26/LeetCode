class Solution {
public:
    int romanToInt(string s) {
        int n = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I') {
                if (i+1 < s.size() && s[i+1] == 'V') {
                    n += 4;
                    i++;
                    continue;
                } else if (i+1 < s.size() && s[i+1] == 'X') {
                    n += 9;
                    i++;
                    continue;
                } else {
                    n++;
                }
            }
            if (s[i] == 'X') {
                if (i+1 < s.size() && s[i+1] == 'L') {
                    n += 40;
                    i++;
                    continue;
                } else if (i+1 < s.size() && s[i+1] == 'C') {
                    n += 90;
                    i++;
                    continue;
                } else {
                    n += 10;
                }
            }
            if (s[i] == 'C') {
                if (i+1 < s.size() && s[i+1] == 'D') {
                    n += 400;
                    i++;
                    continue;
                } else if (i+1 < s.size() && (s[i+1] == 'M')) {
                    n += 900;
                    i++;
                    continue;
                } else {
                    n += 100;
                }
            }
            if (s[i] == 'V') {
                n += 5;
            }
            if (s[i] == 'L') {
                n += 50;
            }
            if (s[i] == 'D') {
                n += 500;
            }
            if (s[i] == 'M') {
                n += 1000;
            }
        }
        return n;
    }
};