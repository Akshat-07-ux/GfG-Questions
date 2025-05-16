//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int k = arr.size();
        int n = arr[0].size();

        // Min heap to store {value, row index, col index}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        int maxVal = INT_MIN;
        // Initialize heap with first element from each list and track maxVal
        for (int i = 0; i < k; ++i) {
            minHeap.push({arr[i][0], i, 0});
            maxVal = max(maxVal, arr[i][0]);
        }

        int range = INT_MAX;
        int start = -1, end = -1;

        while (true) {
            auto curr = minHeap.top();
            minHeap.pop();

            int minVal = curr[0];
            int row = curr[1];
            int col = curr[2];

            // Update the range if smaller
            if (maxVal - minVal < range) {
                range = maxVal - minVal;
                start = minVal;
                end = maxVal;
            }

            // If we reached the end of any list, break (can’t continue with all lists)
            if (col + 1 == arr[row].size()) break;

            // Push next element from the same row into heap
            int nextVal = arr[row][col + 1];
            minHeap.push({nextVal, row, col + 1});
            maxVal = max(maxVal, nextVal);  // Update current max if needed
        }

        return {start, end};
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends