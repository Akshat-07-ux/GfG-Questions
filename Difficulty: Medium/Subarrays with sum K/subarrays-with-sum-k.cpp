//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int countSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> prefixSumCount;
        int currentSum = 0;
        int count = 0;

        // Initialize the hash map to consider cases where subarray starts from index 0
        prefixSumCount[0] = 1;

        for (int num : arr) {
            currentSum += num;

            // Check if there is a prefix sum that fulfills the condition
            int targetPrefixSum = currentSum - k;
            if (prefixSumCount.find(targetPrefixSum) != prefixSumCount.end()) {
                count += prefixSumCount[targetPrefixSum];
            }

            // Update the frequency of the current prefix sum
            prefixSumCount[currentSum]++;
        }

        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends