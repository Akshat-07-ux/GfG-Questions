//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
   public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> temp(n);
        
        // Transform array: >k -> 1, <=k -> -1
        for (int i = 0; i < n; ++i) {
            temp[i] = (arr[i] > k) ? 1 : -1;
        }

        unordered_map<int, int> prefixIndex;
        int maxLen = 0, sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += temp[i];

            // If sum > 0, whole array from 0 to i is valid
            if (sum > 0) {
                maxLen = i + 1;
            } else {
                // If (sum - 1) is found before, we can get a subarray with net +1
                if (prefixIndex.find(sum - 1) != prefixIndex.end()) {
                    maxLen = max(maxLen, i - prefixIndex[sum - 1]);
                }
            }

            // Store the first occurrence of this sum
            if (prefixIndex.find(sum) == prefixIndex.end()) {
                prefixIndex[sum] = i;
            }
        }

        return maxLen;
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
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends