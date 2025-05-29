// User function template for C++

class Solution {
 public:
    vector<int> maximumWeight(int n, vector<vector<int>> edges, int q,
                              vector<int> &queries) {
        vector<int> parent(n + 1), size(n + 1);

        function<int(int)> find = [&](int u) {
            if (parent[u] != u)
                parent[u] = find(parent[u]);
            return parent[u];
        };

        auto unite = [&](int u, int v) {
            int pu = find(u), pv = find(v);
            if (pu == pv) return 0LL;

            long long contrib = 1LL * size[pu] * size[pv];

            if (size[pu] < size[pv]) swap(pu, pv);
            parent[pv] = pu;
            size[pu] += size[pv];

            return contrib;
        };

        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }

        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });

        vector<pair<int, int>> queryPairs;
        for (int i = 0; i < q; ++i) {
            queryPairs.push_back(make_pair(queries[i], i));
        }
        sort(queryPairs.begin(), queryPairs.end());

        vector<int> res(q);
        int idx = 0;
        long long totalPaths = 0;
        for (int i = 0; i < q; ++i) {
            int weight = queryPairs[i].first;
            int qIndex = queryPairs[i].second;

            while (idx < edges.size() && edges[idx][2] <= weight) {
                totalPaths += unite(edges[idx][0], edges[idx][1]);
                idx++;
            }
            res[qIndex] = totalPaths;
        }

        return res;
    }
};