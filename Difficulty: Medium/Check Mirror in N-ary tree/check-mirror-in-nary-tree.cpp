//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // Store children of each node for Tree A in a stack
        unordered_map<int, stack<int>> treeA;
        // Store children of each node for Tree B in a queue
        unordered_map<int, queue<int>> treeB;

        for (int i = 0; i < 2 * e; i += 2) {
            int u = A[i], v = A[i + 1];
            treeA[u].push(v);
        }

        for (int i = 0; i < 2 * e; i += 2) {
            int u = B[i], v = B[i + 1];
            treeB[u].push(v);
        }

        // Compare the children lists
        for (int i = 1; i <= n; ++i) {
            while (!treeA[i].empty() && !treeB[i].empty()) {
                if (treeA[i].top() != treeB[i].front()) {
                    return 0;
                }
                treeA[i].pop();
                treeB[i].pop();
            }
        }

        return 1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends