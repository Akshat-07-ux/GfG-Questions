//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // If the array is empty or has only one interval, return it as is
        if (arr.size() <= 1) return arr;

        // Sort the intervals by their start times
        sort(arr.begin(), arr.end());

        // Initialize a result vector to store the merged intervals
        vector<vector<int>> result;
        // Start with the first interval
        result.push_back(arr[0]);

        // Iterate through the intervals
        for (int i = 1; i < arr.size(); ++i) {
            // Get the last interval in the result
            vector<int>& lastInterval = result.back();

            // Check if the current interval overlaps with the last interval
            if (arr[i][0] <= lastInterval[1]) {
                // Merge the intervals by updating the end time
                lastInterval[1] = max(lastInterval[1], arr[i][1]);
            } else {
                // If no overlap, add the current interval to the result
                result.push_back(arr[i]);
            }
        }

        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends