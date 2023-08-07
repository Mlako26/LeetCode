class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;

        if (nums.size() == 1) {
            return nums[0];
        } else if (nums[0] != nums[1]){
            return nums[0];
        }

        while (i < j - 1) {
            int k = (i + j) / 2; // k siempre es par en la primera al menos
            bool izq = (k % 2 == 0 && nums[k + 1] != nums[k]) || (k % 2 == 1 && nums[k + 1] == nums[k]);
            if (izq) {
                j = k;
            } else {
                i = k;
            }
        }

        return nums[j];
    }
};