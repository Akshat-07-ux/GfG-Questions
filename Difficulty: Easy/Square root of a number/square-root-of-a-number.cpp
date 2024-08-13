//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
 public:
    long long int floorSqrt(long long int n) {
        // Edge case: if n is 0 or 1, return n
        if (n == 0 || n == 1) {
            return n;
        }

        long long int start = 1, end = n, ans = 0;

        while (start <= end) {
            long long int mid = (start + end) / 2;

            // If mid*mid is equal to n, mid is the square root
            if (mid * mid == n) {
                return mid;
            }

            // If mid*mid is less than n, it might be the answer
            if (mid * mid < n) {
                start = mid + 1;
                ans = mid;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends