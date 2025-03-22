//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int robLinear(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int prev2 = 0, prev1 = 0;
        for (int num : nums) {
            int take = num + prev2;
            int skip = prev1;
            int curr = max(take, skip);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        // Two cases:
        // 1. Rob from index 0 to n-2 (excluding last house)
        // 2. Rob from index 1 to n-1 (excluding first house)
        vector<int> case1(arr.begin(), arr.end() - 1);
        vector<int> case2(arr.begin() + 1, arr.end());
        
        return max(robLinear(case1), robLinear(case2));
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends