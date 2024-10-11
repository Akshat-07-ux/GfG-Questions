//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    // Function to print the space-separated array elements
    void printArray(vector<int> &arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (i > 0) cout << " ";  // Add a space before every element except the first one
            cout << arr[i];
        }
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        ob.printArray(arr);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends