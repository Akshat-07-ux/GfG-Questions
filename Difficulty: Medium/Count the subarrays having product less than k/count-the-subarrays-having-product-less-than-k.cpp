//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
 public:
    long long countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long prod = 1;
        int start = 0;
        long long count = 0;

        for (int end = 0; end < n; ++end) {
            // Multiply the current element to the product
            prod *= a[end];

            // Shrink the window from the left until the product is less than k
            while (start <= end && prod >= k) {
                prod /= a[start];
                ++start;
            }

            // The number of subarrays with product less than k ending at 'end'
            count += (end - start + 1);
        }

        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends