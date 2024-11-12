//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        // Step 1: Sort the meetings by their starting time
        sort(arr.begin(), arr.end());
        
        // Step 2: Check for overlapping meetings
        for (int i = 1; i < arr.size(); i++) {
            // If the current meeting starts before the previous one ends, return false
            if (arr[i][0] < arr[i - 1][1]) {
                return false;
            }
        }
        return true;
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
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends