class Solution {
public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        unordered_set<int> elements;
        int n = mat1.size();
        
        // Add all elements from mat2 to the set
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                elements.insert(mat2[i][j]);
            }
        }
        
        int count = 0;
        // For each element in mat1, check if x - mat1[i][j] exists in the set
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int target = x - mat1[i][j];
                if (elements.find(target) != elements.end()) {
                    count++;
                }
            }
        }
        
        return count;
    }
};