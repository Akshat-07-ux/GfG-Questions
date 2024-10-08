//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    bool arraySortedOrNot(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                return false; // If current element is less than previous element, array is not sorted
            }
        }
        return true; // Array is sorted if no such element is found
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        bool ans = ob.arraySortedOrNot(nums);
        cout << (ans ? "true" : "false") << endl;
    }
    return 0;
}

// } Driver Code Ends