//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
   public:
    vector<string> avoidExplosion(vector<vector<int>> mix, int n,
                                   vector<vector<int>> danger, int m) {
        
        // Disjoint Set Union (DSU) - Union-Find
        vector<int> parent(1001); // as constraints go up to 1000
        for(int i = 0; i < 1001; i++) parent[i] = i;

        // Find function with path compression
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };

        // Union function
        auto unionSet = [&](int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px != py) parent[px] = py;
        };

        vector<string> answer;

        for (int i = 0; i < n; i++) {
            int a = mix[i][0], b = mix[i][1];
            int pa = find(a), pb = find(b);
            bool explode = false;

            for (int j = 0; j < m; j++) {
                int p = danger[j][0], q = danger[j][1];
                int pp = find(p), pq = find(q);

                // If a and b are in same flask as a dangerous pair
                if ((pa == pp && pb == pq) || (pa == pq && pb == pp)) {
                    explode = true;
                    break;
                }
            }

            if (explode) {
                answer.push_back("No");
            } else {
                answer.push_back("Yes");
                unionSet(a, b);
            }
        }

        return answer;
    }
};


//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends