//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int pairWithMaxSum(vector<int>& arr) {
        int n = arr.size();
        
        // If the array has less than 2 elements, return -1
        if (n < 2) {
            return -1;
        }

        // Initialize the maximum sum to a very small value
        int maxSum = -1;
        
        // Iterate over adjacent pairs and compute their sum
        for (int i = 0; i < n - 1; ++i) {
            int sum = arr[i] + arr[i + 1];
            maxSum = max(maxSum, sum); // Update the maximum sum
        }
        
        return maxSum;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends