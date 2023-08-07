class Solution {
public:
    string intToRoman(int num) {
        // I'll take out highest Roman Number in each iteration
        string res = {};
        vector<int> vals = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int cur = 0;
        
        while (num > 0 && cur < vals.size()) {
            if (vals[cur] > num) {
                cur++;
            } else {
                num -= vals[cur];
                res.append(roman[cur]);
            }
        }
        
        return res;
    }
};