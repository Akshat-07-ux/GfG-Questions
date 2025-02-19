//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        int d = (arr[n - 1] - arr[0]) / n; // Calculate common difference

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Expected value at index `mid` in a perfect AP
            int expected = arr[0] + mid * d;

            if (arr[mid] != expected) {
                if (mid > 0 && arr[mid - 1] == expected - d) {
                    return expected; // Missing number found
                }
                right = mid - 1; // Search in the left half
            } else {
                left = mid + 1; // Search in the right half
            }
        }
        return -1; // Should never reach here as missing element is guaranteed
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends