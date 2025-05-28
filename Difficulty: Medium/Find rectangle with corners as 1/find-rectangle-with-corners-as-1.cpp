class Solution {
   public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int n = mat.size();
        if (n == 0) return false;
        int m = mat[0].size();

        // Iterate through all pairs of rows
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int count = 0;

                // Check each column
                for (int col = 0; col < m; col++) {
                    // If both rows have 1 in this column
                    if (mat[i][col] == 1 && mat[j][col] == 1) {
                        count++;
                        if (count >= 2) return true; // Found rectangle
                    }
                }
            }
        }

        return false;
    }
};