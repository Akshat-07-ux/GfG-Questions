//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void immediateSmaller(vector<int>& arr, int n) {
        // Traverse the array from 0 to n-2 (because n-1 is the last element)
        for (int i = 0; i < n - 1; i++) {
            // If the next element is smaller, update the current element
            if (arr[i + 1] < arr[i]) {
                arr[i] = arr[i + 1];
            } 
            // Otherwise, set it to -1
            else {
                arr[i] = -1;
            }
        }
        // The last element is always set to -1
        arr[n - 1] = -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends