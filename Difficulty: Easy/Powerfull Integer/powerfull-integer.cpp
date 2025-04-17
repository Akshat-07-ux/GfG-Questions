//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n, vector<vector<int>> &intervals, int k){
        map<int, int> mp;
        
        // Sweep line logic: +1 at start, -1 at end+1
        for(auto &interval : intervals){
            mp[interval[0]]++;
            mp[interval[1]+1]--;
        }
        
        int count = 0;
        int last = -1;
        int result = -1;
        
        for(auto &entry : mp){
            int point = entry.first;
            int delta = entry.second;
            
            // If we were in a zone where count >= k,
            // update the powerful integer range
            if(count >= k){
                result = max(result, point - 1);  // point - 1 because current point is exiting
            }
            
            count += delta;
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends