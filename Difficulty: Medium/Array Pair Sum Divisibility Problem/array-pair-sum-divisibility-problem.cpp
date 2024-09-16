//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool canPair(vector<int> nums, int k) {
        if (nums.size() % 2 != 0) return false;  // Odd number of elements cannot be paired

        unordered_map<int, int> remainderCount;

        // Count the frequency of each remainder when divided by k
        for (int num : nums) {
            int remainder = ((num % k) + k) % k; // Handle negative remainders
            remainderCount[remainder]++;
        }

        // Check for valid pairs
        for (auto& entry : remainderCount) {
            int r = entry.first;
            int countR = entry.second;

            // Special case for remainder 0
            if (r == 0) {
                if (countR % 2 != 0) return false;
            }
            // Special case for remainder k/2 when k is even
            else if (2 * r == k) {
                if (countR % 2 != 0) return false;
            }
            else {
                int complement = (k - r) % k;
                if (remainderCount.find(complement) == remainderCount.end() || remainderCount[complement] != countR) {
                    return false;
                }
            }
        }

        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends