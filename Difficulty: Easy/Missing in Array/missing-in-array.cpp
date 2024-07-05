//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {
        // Calculate the expected sum of numbers from 1 to n
        int expected_sum = n * (n + 1) / 2;
        
        // Calculate the actual sum of the array
        int actual_sum = 0;
        for (int num : arr) {
            actual_sum += num;
        }
        
        // The difference is the missing number
        return expected_sum - actual_sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.missingNumber(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends