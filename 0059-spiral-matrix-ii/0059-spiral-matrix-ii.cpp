class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, (vector<int>(n,0)));
        int top = 0, bot = n - 1, left = 0, right = n - 1;
        int counter = 1;
        while (top <= bot && left <= right) {
            for (int i = left; i <= right; i++) res[top][i] = counter++;
            top++;
            
            for (int i = top; i <= bot; i++) res[i][right] = counter++;
            right--;
            
            for (int i = right; i >= left; i--) res[bot][i] = counter++;
            bot--;
            
            for (int i = bot; i >= top; i--) res[i][left] = counter++;
            left++;
        }
        
        return res;
    }
};