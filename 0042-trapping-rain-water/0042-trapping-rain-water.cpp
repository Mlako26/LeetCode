class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<pair<int,int>> left(n, {-1,0}), right(n, {n,0});  

        for (int i = 0; i < n; i++) {
            pair<int,int> k = {i - 1, 0};
            while (k.first >= 0 && height[k.first] < height[i]) {
                k.second = height[k.first];
                k.first = left[k.first].first;
            }
            left[i] = k;
        }

        for (int i = n - 1; i >= 0; i--) {
            pair<int,int> k = {i + 1, 0};
            while (k.first < n && height[k.first] < height[i]) {
                k.second = height[k.first];
                k.first = right[k.first].first;
            }
            right[i] = k;
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (height[i] == 0) continue;
            if (right[i].first < n) {
                sum += (right[i].first - i - 1) * (height[i] - right[i].second);
            }
            if (left[i].first >= 0 && height[left[i].first] != height[i]) {
                sum += (i - left[i].first - 1) * (height[i] - left[i].second);
            } 
        }

        return sum;
    }
};