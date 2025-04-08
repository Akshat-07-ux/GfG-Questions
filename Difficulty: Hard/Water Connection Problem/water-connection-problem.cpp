//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
      public:
    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
    {
        // Maps for tracking
        vector<int> startHouse(n + 1, 0);  // outgoing pipe from this house
        vector<int> endHouse(n + 1, 0);    // incoming pipe to this house
        vector<int> diameter(n + 1, 0);    // diameter of outgoing pipe from house

        // Fill the maps
        for (int i = 0; i < p; i++) {
            startHouse[a[i]] = b[i];       // a[i] -> b[i]
            endHouse[b[i]] = a[i];         // b[i] <- a[i]
            diameter[a[i]] = d[i];         // diameter of pipe from a[i] to b[i]
        }

        vector<vector<int>> result;

        // Identify source houses (tank houses)
        for (int i = 1; i <= n; i++) {
            if (startHouse[i] != 0 && endHouse[i] == 0) {
                int current = i;
                int minDiameter = 1e9;
                // Traverse till the end tap
                while (startHouse[current] != 0) {
                    minDiameter = min(minDiameter, diameter[current]);
                    current = startHouse[current];
                }
                result.push_back({i, current, minDiameter});
            }
        }

        // Sort based on tank house number
        sort(result.begin(), result.end());

        return result;
    }
};




//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends