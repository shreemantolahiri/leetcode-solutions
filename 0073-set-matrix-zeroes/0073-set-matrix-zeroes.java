class Solution {
    /*
     * Time Complexity: O(m * n)
     * Space Complexity: O(m + n)
     * Solution Type: BRUTE
     * m = number of rows, n = number of columns
     */

    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        int[] row = new int[n]; // to mark columns that need to be zeroed
        int[] col = new int[m]; // to mark rows that need to be zeroed

        // First pass: identify all rows and columns to be zeroed
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[j] = 1; // mark column
                    col[i] = 1; // mark row
                }
            }
        }

        // Second pass: update the matrix based on markings
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[j] == 1 || col[i] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}
