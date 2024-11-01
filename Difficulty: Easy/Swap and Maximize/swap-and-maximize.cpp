//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
public:
    long long maxSum(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<int> arranged;
        int i = 0, j = n - 1;

        // Alternately pick smallest and largest elements
        while (i <= j) {
            if (i <= j) arranged.push_back(arr[i++]);
            if (i <= j) arranged.push_back(arr[j--]);
        }

        // Calculate the sum of absolute differences
        long long maxSum = 0;
        for (int k = 0; k < n; k++) {
            maxSum += abs(arranged[k] - arranged[(k + 1) % n]);
        }

        return maxSum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends