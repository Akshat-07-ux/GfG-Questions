//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to check if it is possible to place k cows with at least 'dist' distance apart
    bool canPlaceCows(vector<int> &stalls, int k, int dist) {
        int count = 1; // Place the first cow in the first stall
        int lastPos = stalls[0]; // Position of the last placed cow

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= dist) {
                count++;
                lastPos = stalls[i]; // Place the next cow here
                if (count == k) {
                    return true;
                }
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end()); // Sort the stall positions

        int low = 1;
        int high = stalls.back() - stalls.front();
        int result = 0;

        // Binary search on the distance
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if it's possible to place all cows with at least 'mid' distance
            if (canPlaceCows(stalls, k, mid)) {
                result = mid; // Update the result as 'mid' is feasible
                low = mid + 1; // Try for a larger distance
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