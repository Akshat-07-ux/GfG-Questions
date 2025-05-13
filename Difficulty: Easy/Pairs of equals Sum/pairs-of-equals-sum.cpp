//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
 public:
    bool findPairs(vector<int>& arr) {
        // Map to store sum -> pair of indices
        unordered_map<int, pair<int, int>> sumMap;

        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = arr[i] + arr[j];

                // If this sum has been seen before with a different pair
                if (sumMap.find(sum) != sumMap.end()) {
                    // We found two pairs with the same sum
                    return true;
                }

                // Otherwise, store this sum with the current pair
                sumMap[sum] = {i, j};
            }
        }

        // No matching pair sums found
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.findPairs(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends