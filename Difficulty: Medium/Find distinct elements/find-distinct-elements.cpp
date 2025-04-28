//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
   public:
    int distinct(vector<vector<int>> M, int N) {
        unordered_map<int, int> mp;
        
        // Insert all elements of first row into the map
        for (int j = 0; j < N; ++j) {
            mp[M[0][j]] = 1;
        }
        
        // For the rest of the rows
        for (int i = 1; i < N; ++i) {
            unordered_set<int> rowElements;
            for (int j = 0; j < N; ++j) {
                rowElements.insert(M[i][j]);
            }
            
            // Update the counts only if the element was seen in previous rows
            for (auto elem : rowElements) {
                if (mp.find(elem) != mp.end() && mp[elem] == i) {
                    mp[elem]++;
                }
            }
        }
        
        // Now count how many elements are present in all N rows
        int count = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (it->second == N) {
                count++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> M(N, vector<int>(N, 0));
        for(int i = 0;i < N*N; i++)
            cin>>M[i/N][i%N];
        
        Solution ob;
        cout<<ob.distinct(M, N)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends