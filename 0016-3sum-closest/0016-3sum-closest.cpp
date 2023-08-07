class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i+1, k = nums.size()-1;
            int best = nums[i] + nums[j] + nums[k];
            while (j < k) {
                int val = nums[i] + nums[j] + nums[k];
                if (abs(val - target) < abs(best - target)) best = val;
                
                if (nums[i] + nums[j] + nums[k] > target) k--;
                else j++;
            }
            
            if (abs(best - target) < abs(res - target)) res = best;    
        }
        
        return res;
    }
};