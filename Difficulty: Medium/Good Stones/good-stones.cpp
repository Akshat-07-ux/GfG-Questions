//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++
class Solution{
public:
    bool dfs(int i, vector<int>& arr, vector<int>& state) {
        if (i < 0 || i >= arr.size()) return true;       // Out of bounds = safe
        if (state[i] == 1) return false;                  // Cycle detected
        if (state[i] == 2) return true;                   // Already marked safe

        state[i] = 1;                                     // Mark as visiting
        int next = i + arr[i];
        bool isSafe = dfs(next, arr, state);
        state[i] = isSafe ? 2 : 0;                        // Mark safe if true, else reset

        return isSafe;
    }

    int goodStones(int n, vector<int> &arr){
        vector<int> state(n, 0);  // 0 = unvisited, 1 = visiting, 2 = safe
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (dfs(i, arr, state)) count++;
        }

        return count;
    }  
};


//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends