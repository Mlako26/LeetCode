class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0 || nums[0] > target || nums[nums.size() - 1] < target) return {-1, -1};
        vector<int> res;
        
        // First we look for the left-most appearance
        int i = 0, j = nums.size() - 1;
        while (i < j - 1) {
            int k = (i + j) / 2;
            if (nums[k] < target) i = k;
            else j = k;
        }
        
        if (nums[i] != target && nums[j] != target) return {-1, -1};
        if (nums[i] == target) res.push_back(i);
        else res.push_back(j);
        
        j = nums.size() - 1;
        while (i < j - 1) {
            int k = (i + j) / 2;
            if (nums[k] > target) j = k;
            else i = k;
        }
        
        if (nums[j] == target) res.push_back(j);
        else res.push_back(i);
        
        return res;
    }
};