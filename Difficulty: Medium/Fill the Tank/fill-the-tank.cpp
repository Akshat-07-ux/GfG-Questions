//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

    public:
    vector<vector<int>> tree;

    bool dfs(int node, int parent, long long water, int* Cap) {
        if (water < Cap[node - 1]) return false;

        long long remaining = water - Cap[node - 1];
        int children = 0;
        for (int child : tree[node]) {
            if (child != parent) children++;
        }

        if (children == 0) return true;

        // Distribute water equally
        if (remaining < children) return false;  // Can't give 1 unit per child
        long long share = remaining / children;

        for (int child : tree[node]) {
            if (child == parent) continue;
            if (!dfs(child, node, share, Cap)) return false;
        }
        return true;
    }

    long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Cap) {
        tree.assign(N + 1, vector<int>());
        for (auto& edge : Edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        long long low = 0, high = 1e18, ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (dfs(S, 0, mid, Cap)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	
cout << "~" << "\n";
}
	
	return 0;
}
// } Driver Code Ends