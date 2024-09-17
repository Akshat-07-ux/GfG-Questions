//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    // Helper function for recursion to calculate all subset sums
    void subsetSumsHelper(int index, int currentSum, const vector<int>& arr, int n, vector<int>& result) {
        // Base case: If we've processed all elements
        if (index == n) {
            result.push_back(currentSum);
            return;
        }
        
        // Recursive case: Two choices, include or exclude the current element
        
        // 1. Exclude the current element
        subsetSumsHelper(index + 1, currentSum, arr, n, result);
        
        // 2. Include the current element
        subsetSumsHelper(index + 1, currentSum + arr[index], arr, n, result);
    }
    
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> result;
        subsetSumsHelper(0, 0, arr, n, result);
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends