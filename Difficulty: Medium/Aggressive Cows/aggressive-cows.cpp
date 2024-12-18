//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to check if it is possible to place k cows with a minimum distance of 'dist'
    bool canPlaceCows(const vector<int>& stalls, int k, int dist) {
        int cowsPlaced = 1; // Place the first cow at the first stall
        int lastPosition = stalls[0];

        for (int i = 1; i < stalls.size(); ++i) {
            if (stalls[i] - lastPosition >= dist) {
                cowsPlaced++;
                lastPosition = stalls[i];

                if (cowsPlaced == k) {
                    return true; // Successfully placed all cows
                }
            }
        }
        return false; // Not possible to place all cows
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        // Sort the stall positions
        sort(stalls.begin(), stalls.end());

        // Binary search on the minimum distance
        int low = 1; // Minimum possible distance
        int high = stalls.back() - stalls.front(); // Maximum possible distance
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlaceCows(stalls, k, mid)) {
                result = mid; // Update the result and try for a larger distance
                low = mid + 1;
            } else {
                high = mid - 1; // Try for a smaller distance
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends