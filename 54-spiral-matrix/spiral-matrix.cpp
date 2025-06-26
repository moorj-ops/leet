class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {}; // Handle empty matrix

        int firstrow = 0;
        int firstcolm = 0;
        int lastrow = matrix.size() - 1;
        int lastcolm = matrix[0].size() - 1;

        vector<int> spiral;

        while (firstrow <= lastrow && firstcolm <= lastcolm) {
            // Traverse from left to right
            for (int i = firstcolm; i <= lastcolm; i++) {
                spiral.push_back(matrix[firstrow][i]);
            }
            firstrow++;

            // Traverse from top to bottom
            for (int i = firstrow; i <= lastrow; i++) {
                spiral.push_back(matrix[i][lastcolm]);
            }
            lastcolm--;

            // Traverse from right to left (if there are still rows left)
            if (firstrow <= lastrow) {
                for (int i = lastcolm; i >= firstcolm; i--) {
                    spiral.push_back(matrix[lastrow][i]);
                }
                lastrow--;
            }

            // Traverse from bottom to top (if there are still columns left)
            if (firstcolm <= lastcolm) {
                for (int i = lastrow; i >= firstrow; i--) {
                    spiral.push_back(matrix[i][firstcolm]);
                }
                firstcolm++;
            }
        }
        
        return spiral;
    }
};
