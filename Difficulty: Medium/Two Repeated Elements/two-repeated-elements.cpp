//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int n, int arr[]) {
        vector<int> result; // To store the two repeating elements
        // Traverse the array to find the two repeating numbers
        for (int i = 0; i < n + 2; i++) {
            int index = abs(arr[i]) - 1; // Find index corresponding to current element
            
            // If the value at the computed index is negative, then it's a repeat
            if (arr[index] < 0) {
                result.push_back(abs(arr[i])); // Add the repeating element to the result
            } else {
                // Mark the element as seen by negating the value at the computed index
                arr[index] = -arr[index];
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        int arr[n + 2];

        for (int i = 0; i < n + 2; i++)
            cin >> arr[i];

        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(n, arr);
        cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}

// } Driver Code Ends