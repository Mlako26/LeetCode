class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i+1;
            int k = nums.size() - 1;
            
            while (j != k) {
                if (nums[i] + nums[j] + nums[k] > 0) k--;
                else if (nums[i] + nums[j] + nums[k] < 0) j++;
                else {
                    int aux1 = nums[j], aux2 = nums[k];
                    res.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == aux1) j++;
                    while(j < k && nums[k] == aux2) k--;
                }
            }
            
            while (i < nums.size() - 2 && nums[i] == nums[i+1]) i++;
        }

        return res;
    }
};