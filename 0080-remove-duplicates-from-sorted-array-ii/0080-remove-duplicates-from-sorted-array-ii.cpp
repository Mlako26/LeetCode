class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current = 0, next = 0;
        int count = 0;
        
        while (next < nums.size()) {
            if ((count == 1 && nums[next-1] == nums[next]) || !count) {
                count++;
            } else {
                count = 1;
                while (next < nums.size() && nums[next-1] == nums[next]) next++;
                if (next == nums.size()) break;
            }
            
            nums[current] = nums[next];
            current++;
            next++;
        }
        
        return current;
    }
};