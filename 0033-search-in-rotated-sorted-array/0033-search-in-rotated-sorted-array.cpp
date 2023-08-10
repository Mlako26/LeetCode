class Solution {
public:
    int search(vector<int>& nums, int target) {
        // First I must find the pivot
        int i = 0, j = nums.size() - 1;
        
        while (i <= j) {
            int k = (i + j) / 2;
            
            if (nums[k] == target) return k;
            
            if (nums[i] <= nums[k]) {
                if (target < nums[k] && target >= nums[i]) j = k - 1;
                else i = k + 1;
            } else {
                if (target > nums[k] && target <= nums[j]) i = k + 1;
                else j = k - 1;
            }
        }
        
        return -1;
        
//         int pivot = nums[i] < nums[j] ? i : j;
        
//         // Then I look for the element on one side or the other of the pivot
//         i = 0;
//         j = pivot - 1;
        
//         while (i <= j) {
//             int k = (i + j) / 2;
            
//             if (nums[k] == target) return k;
//             else if (nums[k] < target) i = k + 1;
//             else j = k - 1;
//         }
        
//         i = pivot;
//         j = nums.size() - 1;
        
//          while (i <= j) {
//             int k = (i + j) / 2;
            
//             if (nums[k] == target) return k;
//             else if (nums[k] < target) i = k + 1;
//             else j = k - 1;
//         }
        
//         return -1;     
    }
};