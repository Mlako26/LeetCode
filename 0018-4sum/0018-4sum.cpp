class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int a = 0; a < n - 3; a++) {
            for (int b = a + 1; b < n - 2; b++) {
                int c = b + 1, d =  n - 1;
                while (c < d) {
                    long val = long(nums[a]) + long(nums[b]) + long(nums[c]) + long(nums[d]);
                    if (val < long(target)) c++;
                    else if (val > long(target)) d--;
                    else {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                        int aux1 = nums[c], aux2 = nums[d];
                        while (c < d && nums[c] == aux1) c++;
                        while (c < d && nums[d] == aux2) d--;
                    } 
                }
                while (b < n - 2 && nums[b] == nums[b+1]) b++;
            }
            while (a < n - 3 && nums[a] == nums[a+1]) a++;
        }

        return res;
    }
};