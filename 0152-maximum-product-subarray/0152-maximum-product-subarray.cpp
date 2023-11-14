class Solution {
public:


int maxProduct(vector<int>& nums) {
    int ans = nums[0], mx = nums[0], mn = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int n = nums[i];
        if (n < 0) {
            swap(mn, mx);
        }

        mx = max(mx * n, n);
        mn = min(mn * n, n);

        ans = max(ans, mx);
    }
    return ans;
}
};