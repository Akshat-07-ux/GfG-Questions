//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    bool find3Numbers(int arr[], int n, int x) {
        // Sort the array
        sort(arr, arr + n);
        
        // Fix the first element and find other two
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = arr[i] + arr[left] + arr[right];
                
                if (currentSum == x) {
                    return true;
                }
                
                if (currentSum < x) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends