//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<int> findIndex(vector<int>& arr, int key) {
        int n = arr.size();
        int start = -1, end = -1;
        
        // Traverse the array to find the first and last occurrence of key
        for (int i = 0; i < n; ++i) {
            if (arr[i] == key) {
                if (start == -1) {
                    start = i; // First occurrence
                }
                end = i; // Update last occurrence
            }
        }
        
        // Return the result as a vector [start, end]
        return {start, end};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> res;
        vector<int> arr;
        string s;
        getline(cin, s);
        stringstream ss(s);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int key;
        cin >> key;
        cin.ignore();
        Solution ob;
        res = ob.findIndex(arr, key);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends