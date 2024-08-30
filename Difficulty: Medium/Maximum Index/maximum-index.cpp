//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // Create arrays to store minimum values from the start and maximum values from the end
        int LMin[n], RMax[n];
        
        // Fill LMin array
        LMin[0] = arr[0];
        for (int i = 1; i < n; i++) {
            LMin[i] = std::min(LMin[i - 1], arr[i]);
        }
        
        // Fill RMax array
        RMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            RMax[i] = std::max(RMax[i + 1], arr[i]);
        }
        
        // Traverse LMin and RMax to find the maximum difference
        int i = 0, j = 0, maxDiff = 0;
        while (j < n) {
            if (LMin[i] <= RMax[j]) {
                maxDiff = std::max(maxDiff, j - i);
                j++;
            } else {
                i++;
            }
        }
        
        return maxDiff;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends