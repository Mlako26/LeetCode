class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int best = 0;
        int n = nums.size() / 2;
        for (int i = 0; i < n; i++) {
            int pairSum = nums[i] + nums[nums.size() - i - 1];
            if (best < pairSum) best = pairSum; 
        }
        
        return best;
    }
};