class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans = {{}};
        int i = 0, lastIdx = -1;
        while (i < nums.size()) {
            int n = ans.size(), k;

            if (i - 1 >= 0 && nums[i - 1] == nums[i]) {
                k = lastIdx;
            } else {
                k = 0;
            }

            lastIdx = n;

            for (int j = k; j < n; j++) {
                vector<int> v = ans[j];
                v.push_back(nums[i]);
                ans.push_back(v);
            }

            i++;
        }
        return ans;
    }
};