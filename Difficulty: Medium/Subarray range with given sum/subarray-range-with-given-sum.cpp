//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(std::vector<int>& arr, int tar) {
        std::unordered_map<int, int> prefixSumCount;
        int currentSum = 0;
        int count = 0;

        // Initialize with the prefix sum of 0 to handle cases where a subarray itself starts from the beginning and sums to `tar`.
        prefixSumCount[0] = 1;

        for (int num : arr) {
            // Update the current sum
            currentSum += num;

            // Check if there is a subarray (prefix) we can remove to get the sum `tar`
            if (prefixSumCount.find(currentSum - tar) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - tar];
            }

            // Add the current sum to the prefix sum map
            prefixSumCount[currentSum]++;
        }

        return count;
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
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends