#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int findParent(int u) {
        if (parent[u] != u)
            parent[u] = findParent(parent[u]);  // Path compression
        return parent[u];
    }

    bool unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return false;

        // Union by rank
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // Sort the edges by weight
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });

        DisjointSet ds(V);
        int mstWeight = 0;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // If u and v are in different sets, add the edge to the MST
            if (ds.unionByRank(u, v)) {
                mstWeight += w;
            }
        }

        return mstWeight;
    }
};
