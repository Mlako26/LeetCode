class Solution {
public:
    bool solve(vector<int>& nums, vector<int>& mem, int i) {
        if (mem[i] != -1) return mem[i];
        if (i == nums.size() - 1) return true;
        
        bool res = false;
        for (int j = 1; j <= nums[i] && j + i < nums.size(); j++) {
            res = res || solve(nums, mem, i+j);
        }
        return mem[i] = res;
    }
    
    bool canJump(vector<int>& nums) {
        vector<int> mem(nums.size(), -1);
        return solve(nums, mem, 0);
    }
};