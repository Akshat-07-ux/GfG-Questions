//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        stack<int> s;
        int root = -1; // initialize root to minimum possible (0 works as well if 0 is allowed in arr)

        for (int i = 0; i < N; i++) {
            // If we find a node who is on the left of root, it's invalid
            if (arr[i] < root)
                return 0;

            // While stack is not empty and current value is greater than top of stack
            // keep popping and update root
            while (!s.empty() && arr[i] > s.top()) {
                root = s.top();
                s.pop();
            }

            // Push current element to stack
            s.push(arr[i]);
        }

        return 1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends