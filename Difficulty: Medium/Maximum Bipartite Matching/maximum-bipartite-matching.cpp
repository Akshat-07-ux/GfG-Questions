//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool bpm(int u, vector<vector<int>>& G, vector<bool>& seen, vector<int>& matchR, int N) {
        for (int v = 0; v < N; v++) {
            if (G[u][v] && !seen[v]) {
                seen[v] = true;

                // If job is not assigned OR previously assigned applicant can be reassigned
                if (matchR[v] < 0 || bpm(matchR[v], G, seen, matchR, N)) {
                    matchR[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    int maximumMatch(vector<vector<int>>& G) {
        int M = G.size();        // Applicants
        int N = G[0].size();     // Jobs

        vector<int> matchR(N, -1); // matchR[j] = applicant assigned to job j

        int result = 0;
        for (int u = 0; u < M; u++) {
            vector<bool> seen(N, false);
            if (bpm(u, G, seen, matchR, N))
                result++;
        }
        return result;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends