//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    bool isProduct(vector<int> arr, long long x) {
        unordered_set<long long> seen; // To store the elements we've encountered

        for (int num : arr) {
            // Check if num is a valid divisor of x
            if (num != 0 && x % num == 0) {
                long long complement = x / num;
                // If the complement exists in the set, we found a pair
                if (seen.find(complement) != seen.end()) {
                    return true;
                }
            }
            // Add the current number to the set
            seen.insert(num);
        }

        return false; // No such pair found
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        long long x;
        cin >> x;
        cin.ignore(); // To discard any leftover newline characters

        Solution ob;
        auto ans = ob.isProduct(arr, x);
        cout << (ans ? "true\n" : "false\n");
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends