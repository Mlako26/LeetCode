class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> c1(26, 0), c2(26, 0);
        for (char p : s1) c1[p - 'a']++;
        int l = 0, r = 0;
        while (r < s1.size()) c2[s2[r++] - 'a']++;
        bool res = false;
        while (!res && r < s2.size()) {
            if (c1 == c2) res = true;
            else {
                c2[s2[l++] - 'a']--;
                c2[s2[r++] - 'a']++;
            }
        }
        return res || c1 == c2;
    }
};