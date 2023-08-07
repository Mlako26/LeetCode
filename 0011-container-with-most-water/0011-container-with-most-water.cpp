class Solution {
public:
    int maxArea(vector<int>& height) {
        int best = 0, left = 0, right = height.size() - 1;
        
        while (left < right) {
            best = max(best, (right - left) * min(height[right], height[left]));
            
            if (height[right] > height[left]) {
                left++;
            } else {
                right--;
            }
        }
        
        return best;
    }
};