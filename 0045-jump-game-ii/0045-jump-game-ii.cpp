class Solution {
private:
    int solve(vector<int> &nums, vector<int> &mem, int i) {
        if (i == nums.size() - 1) return 0;
        if (mem[i] != -1) return mem[i];      
        if (i + nums[i] >= nums.size() - 1) return mem[i] = 1;
    
        int res = INT_MAX;
        for (int j = 1; j <= nums[i] && j + i < nums.size(); j++) {
            int aux = solve(nums, mem, j + i);
            if (aux < INT_MAX && aux + 1 < res) res = aux + 1;
        }
        return mem[i] = res;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> mem(nums.size(), -1);
        return solve(nums, mem, 0);        
    }
};