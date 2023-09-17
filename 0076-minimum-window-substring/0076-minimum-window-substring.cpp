class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> lt, ls;
        int cant = t.size();
        for (char c: t) lt[c]++;
        ls = lt;

        int l = 0, r;
        while (l < s.size() && !lt.count(s[l])) l++;
        r = l;

        string best = s;
        bool sePudo = false;
        while (r < s.size()) {
            while (r < s.size() && cant) {
                char c = s[r];
                if (ls.count(c)) {
                    if (ls[c] > 0) cant--;
                    ls[c]--;
                }
                r++;
            }

            while (l < s.size() && !cant) {
                char c = s[l];
                if (ls.count(c)) {
                    if(ls[c] == 0) {
                        best = best.size() < r-l ? best : s.substr(l, r-l);
                        sePudo = true;
                        cant++;
                    }
                    ls[c]++;
                }
                l++;
            }
        }

        if (sePudo) return best;
        else return "";
    }
};