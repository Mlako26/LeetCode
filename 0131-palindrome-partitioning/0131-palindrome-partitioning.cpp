class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            int l = 0, r = i;
            bool palindrome = true;
            while (palindrome && l <= r) {
                if (s[l] != s[r]) palindrome = false;
                l++;
                r--;
            }
            if (palindrome) {
                string cut = s.substr(0, i+1);
                vector<vector<string>> aux = partition(s.substr(i+1));
                for (auto v : aux) {
                    vector<string> next = {cut};
                    for (auto t : v) {
                        next.push_back(t);
                    }
                    ans.push_back(next);
                }
                if (i == n-1) ans.push_back({cut});
            }
        }
        return ans;
    }
};