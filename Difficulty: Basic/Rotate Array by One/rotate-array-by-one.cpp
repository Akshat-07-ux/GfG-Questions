//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
    void rotate(vector<int> &arr) {
        int n = arr.size();
        if (n <= 1) return; // No need to rotate if array has 0 or 1 element
        
        int last = arr[n - 1]; // Store the last element
        // Shift elements to the right
        for (int i = n - 1; i > 0; --i) {
            arr[i] = arr[i - 1];
        }
        arr[0] = last; // Place the last element at the front
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
        ob.rotate(arr);
        for (long long i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends