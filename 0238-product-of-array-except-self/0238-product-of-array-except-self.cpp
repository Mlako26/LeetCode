class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pref, suff, res;
        
        pref.push_back(nums[0]);
        suff.push_back(nums[nums.size() - 1]);
        for (int i = 1; i < nums.size(); i++) {
            pref.push_back(pref.back() * nums[i]);
            suff.push_back(suff.back() * nums[nums.size() - 1 - i]);
        }
        
        res.push_back(suff[nums.size() - 2]);
        for (int i = 1; i < nums.size() - 1; i++) {
            res.push_back(suff[nums.size() - 2 - i] * pref[i - 1]);
        }
        res.push_back(pref[nums.size() - 2]);
        
        return res;
    }
};