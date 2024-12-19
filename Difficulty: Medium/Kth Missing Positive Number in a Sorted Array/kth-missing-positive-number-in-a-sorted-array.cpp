//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
 public:
    int kthMissing(vector<int> &arr, int k) {
        int left = 0, right = arr.size() - 1;

        // Binary search to find the position where kth missing lies
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // Count of missing numbers before arr[mid]
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                left = mid + 1; // Move right to find more missing numbers
            } else {
                right = mid - 1; // Move left to reduce missing numbers
            }
        }

        // At the end of binary search, left is the position where kth missing lies
        // Calculate the kth missing number
        return left + k;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends