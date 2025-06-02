// ✅ MOST OPTIMAL Solution  
// ⏱️ Time Complexity: O(m * n)  
// \U0001f4be Space Complexity: O(1) (in-place, using matrix itself for marking)

class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        int firstRow = 1; // Flag to check if first row needs to be zeroed

        // Check if any cell in the first row is 0
        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0)
                firstRow = 0;

        // Mark rows and columns to be zeroed using first row and first column
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0; // mark this column
                    matrix[i][0] = 0; // mark this row
                }
            }
        }

        // Set matrix cells to 0 based on markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
        // Handle first column separately if needed (tracked via matrix[0][0])
        if (matrix[0][0] == 0) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
        // Handle first row separately if needed
        if (firstRow == 0) {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }

        
    }
}
