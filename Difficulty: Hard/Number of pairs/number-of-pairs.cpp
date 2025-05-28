// User function Template for C++

class Solution {
 public:
    vector<int> parent, size;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) {
            if (size[px] < size[py]) swap(px, py); // union by size
            parent[py] = px;
            size[px] += size[py];
        }
    }

    long long int numberOfPairs(vector<vector<int>> &pairs, int p, int n) {
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; ++i) parent[i] = i;

        for (auto &pair : pairs) {
            unite(pair[0], pair[1]);
        }

        unordered_map<int, int> groupSizes;
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            groupSizes[root]++;
        }

        long long totalPairs = 1LL * n * (n - 1) / 2;
        long long sameBranchPairs = 0;

        for (auto &entry : groupSizes) {
            long long sz = entry.second;
            sameBranchPairs += sz * (sz - 1) / 2;
        }

        return totalPairs - sameBranchPairs;
    }
};
