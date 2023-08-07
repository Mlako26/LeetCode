class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, bool> aux;
        int res = 0;
        int counter = 0;
        for (int i = 0; i < s.size(); i++) {
            if (aux[s[i]] == true) {
                aux.clear();
                if (counter > res) res = counter;
                counter = 0;
                int j = i - 1;
                while (s[j] != s[i]) --j;
                i = j+1;
            }
            aux[s[i]] = true;
            counter++;
        }
        if (counter > res) res = counter;
        return res;
    }
};