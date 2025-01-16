//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxLen(vector<int> &arr) {
        unordered_map<int, int> prefixSumIndex; // To store prefix sum and its index
        int maxLength = 0;
        int prefixSum = 0;

        // Traverse the array
        for (int i = 0; i < arr.size(); i++) {
            // Treat 0 as -1 for calculation
            prefixSum += (arr[i] == 0 ? -1 : 1);

            // If prefix sum is 0, then subarray [0...i] has equal 0s and 1s
            if (prefixSum == 0) {
                maxLength = i + 1;
            }

            // Check if the prefix sum has been seen before
            if (prefixSumIndex.find(prefixSum) != prefixSumIndex.end()) {
                // Update maxLength if the current subarray is longer
                maxLength = max(maxLength, i - prefixSumIndex[prefixSum]);
            } else {
                // Store the first occurrence of this prefix sum
                prefixSumIndex[prefixSum] = i;
            }
        }

        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends