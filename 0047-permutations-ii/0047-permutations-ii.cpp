class Solution {
private:
    void solve(vector<vector<int>> &res, int &n, vector<int> &available, vector<int> &quant, vector<int> &s) {
        if (s.size() == n) {
            res.push_back(s);
            return;
        }
        
        for (int i = 0; i < available.size(); i++) {
            if (quant[i] > 0) {
                quant[i]--;
                s.push_back(available[i]);
                solve(res, n, available, quant, s);
                quant[i]++;
                s.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> s;
        vector<int> available;
        vector<int> quant;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        int last = nums[0], counter = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == last) counter++;
            else {
                available.push_back(last);
                quant.push_back(counter);
                last = nums[i];
                counter = 1;
            }
        }
        available.push_back(last);
        quant.push_back(counter);
        
        solve(res, n, available, quant, s);
        
        return res;
    }
};