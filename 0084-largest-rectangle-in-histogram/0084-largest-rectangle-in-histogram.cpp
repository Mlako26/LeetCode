class Solution {
public:
   int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1), right(n, n);

        for (int i = 0; i < n; i++) {
            int k = i - 1;
            while (k >= 0 && heights[k] >= heights[i]) {
                k = left[k];
            }
            left[i] = k;
        }

        for (int i = n - 1; i >= 0; i--) {
            int k = i + 1;
            while (k < n && heights[k] >= heights[i]) {
                k = right[k];
            }
            right[i] = k;
        }

        int best = 0;
        for (int i = 0; i < n; i++) {
            int bars = right[i] - left[i] - 1;
            int rect = heights[i] * bars;
            if (rect > best) best = rect;
        }

        return best;
    }

};