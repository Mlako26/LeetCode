class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // First I'll look for the correct row and then for the correct column
        int m = matrix.size(), n = matrix[0].size();
        
        int i = 0, j = m - 1;
        while (i < j - 1) {
            int k = (i + j) / 2;
            
            if (matrix[k][0] > target) j = k;
            else i = k;
        }
        
        int row = target >= matrix[j][0] ? j : i;
        i = 0;
        j = n - 1;
        
        while (i <= j) {
            int k = (i + j) / 2;
            
            if (matrix[row][k] == target) return true;
            else if (matrix[row][k] < target) i = k + 1;
            else j = k - 1;
        }
        
        return false;
    }
};