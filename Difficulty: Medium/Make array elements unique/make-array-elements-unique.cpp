//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int minIncrements(vector<int>& arr) {
        // Sort the array to easily detect duplicates
        sort(arr.begin(), arr.end());

        int count = 0;
        // Traverse through the sorted array
        for (int i = 1; i < arr.size(); i++) {
            // If the current element is not greater than the previous one
            if (arr[i] <= arr[i - 1]) {
                // Calculate how much we need to increment
                int increment = arr[i - 1] - arr[i] + 1;
                // Increment the current element to make it unique
                arr[i] += increment;
                // Accumulate the total number of increments
                count += increment;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends