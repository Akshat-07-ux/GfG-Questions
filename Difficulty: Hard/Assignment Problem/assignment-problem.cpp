//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int assignmentProblem(int cost[], int N) {
        // Convert 1D array to 2D cost matrix
        vector<vector<int>> C(N, vector<int>(N));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                C[i][j] = cost[i * N + j];

        vector<int> u(N + 1), v(N + 1), p(N + 1), way(N + 1);
        for (int i = 1; i <= N; ++i) {
            p[0] = i;
            vector<int> minv(N + 1, INT_MAX);
            vector<bool> used(N + 1, false);
            int j0 = 0;

            do {
                used[j0] = true;
                int i0 = p[j0], delta = INT_MAX, j1;

                for (int j = 1; j <= N; ++j) {
                    if (!used[j]) {
                        int cur = C[i0 - 1][j - 1] - u[i0] - v[j];
                        if (cur < minv[j]) {
                            minv[j] = cur;
                            way[j] = j0;
                        }
                        if (minv[j] < delta) {
                            delta = minv[j];
                            j1 = j;
                        }
                    }
                }

                for (int j = 0; j <= N; ++j) {
                    if (used[j]) {
                        u[p[j]] += delta;
                        v[j] -= delta;
                    } else {
                        minv[j] -= delta;
                    }
                }

                j0 = j1;
            } while (p[j0] != 0);

            do {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0);
        }

        return -v[0]; // Total minimum cost
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        
        int Arr[n*n];
        for(int i=0; i<n*n; i++)
            cin>>Arr[i];

        Solution ob;
        cout << ob.assignmentProblem(Arr,n) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends