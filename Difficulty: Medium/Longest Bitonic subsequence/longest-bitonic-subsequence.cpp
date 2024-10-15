//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        if (n == 0) return 0;
        
        // Step 1: Compute LIS for each element
        vector<int> LIS(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && LIS[i] < LIS[j] + 1) {
                    LIS[i] = LIS[j] + 1;
                }
            }
        }

        // Step 2: Compute LDS for each element
        vector<int> LDS(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j] && LDS[i] < LDS[j] + 1) {
                    LDS[i] = LDS[j] + 1;
                }
            }
        }

        // Step 3: Find the maximum value of LIS[i] + LDS[i] - 1
        int maxBitonicLength = 0;
        for (int i = 0; i < n; i++) {
            if (LIS[i] > 1 && LDS[i] > 1) {  // Ensure both increasing and decreasing parts exist
                maxBitonicLength = max(maxBitonicLength, LIS[i] + LDS[i] - 1);
            }
        }

        return maxBitonicLength;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
    }
}

// } Driver Code Ends