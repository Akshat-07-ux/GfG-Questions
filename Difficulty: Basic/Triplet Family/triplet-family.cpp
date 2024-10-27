//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    bool findTriplet(vector<int>& arr) {
        int n = arr.size();
        
        // Sort the array
        sort(arr.begin(), arr.end());
        
        // Iterate over each element as the possible third element in the triplet
        for (int k = n - 1; k >= 2; k--) {
            int target = arr[k];
            int i = 0, j = k - 1;
            
            // Use two pointers to find if there exists a pair (arr[i], arr[j]) such that arr[i] + arr[j] == target
            while (i < j) {
                int sum = arr[i] + arr[j];
                if (sum == target) {
                    return true; // Triplet found
                } else if (sum < target) {
                    i++;
                } else {
                    j--;
                }
            }
        }
        
        return false; // No such triplet exists
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
        bool res = obj.findTriplet(arr);
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