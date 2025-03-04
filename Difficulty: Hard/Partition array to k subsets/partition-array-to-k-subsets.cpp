//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this method */
class Solution {
private:
    bool canPartition(vector<int> &arr, vector<int> &subsetSum, int index, int target, int k) {
        if (index == arr.size()) {
            // Check if all subsets have the target sum
            return all_of(subsetSum.begin(), subsetSum.end(), [&](int sum) { return sum == target; });
        }
        
        // Try placing arr[index] in one of the subsets
        for (int i = 0; i < k; i++) {
            if (subsetSum[i] + arr[index] <= target) {
                subsetSum[i] += arr[index];
                
                if (canPartition(arr, subsetSum, index + 1, target, k))
                    return true;
                
                // Backtrack
                subsetSum[i] -= arr[index];

                // Optimization: If the current subset is empty, no need to try further
                if (subsetSum[i] == 0) break;
            }
        }
        return false;
    }

  public:
    bool isKPartitionPossible(vector<int> &arr, int k) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        if (k > arr.size() || totalSum % k != 0)
            return false;  // If k > array size or total sum is not divisible by k

        int target = totalSum / k;
        vector<int> subsetSum(k, 0);
        
        // Sorting in descending order to optimize backtracking
        sort(arr.rbegin(), arr.rend());

        return canPartition(arr, subsetSum, 0, target, k);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> a;
        int n;
        while (ss >> n)
            a.push_back(n);
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        if (obj.isKPartitionPossible(a, k))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends