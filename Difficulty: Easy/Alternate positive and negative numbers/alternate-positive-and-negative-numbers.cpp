//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    void rearrange(vector<int> &arr) {
        vector<int> pos; // To store positive numbers (including 0)
        vector<int> neg; // To store negative numbers
        
        // Separate positive and negative numbers
        for (int num : arr) {
            if (num >= 0) {
                pos.push_back(num); // Positive numbers and 0
            } else {
                neg.push_back(num); // Negative numbers
            }
        }
        
        int i = 0, j = 0, k = 0;
        bool toggle = true; // To alternate between pos and neg
        
        // Merge the two lists alternately
        while (i < pos.size() && j < neg.size()) {
            if (toggle) {
                arr[k++] = pos[i++]; // Place a positive number
            } else {
                arr[k++] = neg[j++]; // Place a negative number
            }
            toggle = !toggle; // Toggle between positive and negative
        }
        
        // If positive numbers are left
        while (i < pos.size()) {
            arr[k++] = pos[i++];
        }
        
        // If negative numbers are left
        while (j < neg.size()) {
            arr[k++] = neg[j++];
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends