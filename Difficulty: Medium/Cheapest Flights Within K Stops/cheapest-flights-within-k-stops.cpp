//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Adjacency List Representation: graph[from] -> {to, price}
        vector<pair<int, int>> graph[n];
        for (auto& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        // Min-Heap / Priority Queue: {cost, current city, stops remaining}
        queue<vector<int>> q;
        q.push({0, src, K + 1});  // (cost, city, remaining stops)

        // Distance Array: To store minimum cost to reach each city
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            int currCost = current[0];
            int city = current[1];
            int stopsLeft = current[2];

            // If we have stops remaining, explore neighbors
            if (stopsLeft > 0) {
                for (auto& neighbor : graph[city]) {
                    int nextCity = neighbor.first;
                    int nextCost = neighbor.second;

                    // If we find a cheaper way to reach nextCity, update it
                    if (currCost + nextCost < cost[nextCity]) {
                        cost[nextCity] = currCost + nextCost;
                        q.push({cost[nextCity], nextCity, stopsLeft - 1});
                    }
                }
            }
        }

        // Return the minimum cost to reach destination or -1 if unreachable
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends