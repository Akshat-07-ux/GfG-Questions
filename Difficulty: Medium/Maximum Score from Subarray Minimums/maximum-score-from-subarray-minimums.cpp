//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
 public:
    // Function to find the maximum sum of the smallest and second smallest in any subarray
    int pairWithMaxSum(vector<int> &arr) {
        int maxSum = 0;
        int n = arr.size();

        // Traverse the array and check sum of every adjacent pair
        for (int i = 0; i < n - 1; i++) {
            maxSum = max(maxSum, arr[i] + arr[i + 1]);
        }
        
        return maxSum;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.pairWithMaxSum(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends