//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
 public:
    vector<int> countEleLessThanOrEqual(vector<int>& a, vector<int>& b) {
        // Step 1: Sort the array b
        sort(b.begin(), b.end());

        vector<int> result;
        
        // Step 2: For each element in a, find the count of elements in b that are <= to it
        for (int num : a) {
            // Use upper_bound to find the first element greater than num
            int count = upper_bound(b.begin(), b.end(), num) - b.begin();
            result.push_back(count);
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.countEleLessThanOrEqual(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends