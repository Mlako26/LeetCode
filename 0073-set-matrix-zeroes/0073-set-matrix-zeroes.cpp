class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), columns = matrix[0].size();
        int firstColumn = 1;
        
        // First read the 0's and mark them inplace
        for (int currentRow = 0; currentRow < rows; currentRow++) {
            
            if (matrix[currentRow][0] == 0) firstColumn = 0;
            
            for (int currentColumn = 1; currentColumn < columns; currentColumn++) {
                if (matrix[currentRow][currentColumn] == 0) {
                    matrix[currentRow][0] = 0;
                    matrix[0][currentColumn] = 0;
                }
            }
        }
        
        // Then I add the zeroes bottom-up
        for (int currentRow = rows - 1; currentRow >= 0; currentRow--) {
            for (int currentColumn = columns - 1; currentColumn >= 1; currentColumn--) {
                if (matrix[currentRow][0] == 0 || matrix[0][currentColumn] == 0) {
                    matrix[currentRow][currentColumn] = 0;
                }
            }
            if (firstColumn == 0) matrix[currentRow][0] = 0;
        }
    }
};