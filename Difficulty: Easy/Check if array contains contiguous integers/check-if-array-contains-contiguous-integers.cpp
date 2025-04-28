//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
 public:
    // Function to check whether the array contains
    // a set of contiguous integers
    bool areElementsContiguous(vector<int>& arr) {
        unordered_set<int> s;
        
        int mini = INT_MAX, maxi = INT_MIN;
        
        for (int num : arr) {
            s.insert(num);
            mini = min(mini, num);
            maxi = max(maxi, num);
        }
        
        // Check if number of unique elements == (max - min + 1)
        if (s.size() == (maxi - mini + 1)) {
            return true;
        } else {
            return false;
        }
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
        bool res = obj.areElementsContiguous(arr);
        if (res)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends