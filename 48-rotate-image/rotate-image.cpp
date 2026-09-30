class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int done = 0;
        while(done < matrix.size() / 2) {
            for(int i = done; i < matrix.size() - done - 1; i++) {
                int temp = matrix[done][i]; // Top
                // Left to Top
                matrix[done][i] = matrix[matrix.size() - 1 - i][done]; 
                // Bottom to Left
                matrix[matrix.size() - 1 - i][done] = matrix[matrix.size() - 1 - done][matrix.size() - 1 - i]; 
                // Right to Bottom
                matrix[matrix.size() - 1 - done][matrix.size() - 1 - i] = matrix[i][matrix.size() - 1 - done];
                // Top to Right
                matrix[i][matrix.size() - 1 - done] = temp; 
            }
            done++;
        }
    }
};