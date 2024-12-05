//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
 public:
    vector<int> getMoreAndLess(vector<int> &arr, int x) {
        int n = arr.size();

        // Find the number of elements less than or equal to x
        int lessOrEqual = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

        // Find the number of elements greater than or equal to x
        int greaterOrEqual = n - (lower_bound(arr.begin(), arr.end(), x) - arr.begin());

        return {lessOrEqual, greaterOrEqual};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        vector<int> ans = ob.getMoreAndLess(arr, x);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends