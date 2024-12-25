//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
        // Create a vector of pairs to store {finish_time, start_time, original_index}
        vector<pair<pair<int, int>, int>> meetings;
        for(int i = 0; i < N; i++) {
            meetings.push_back({{F[i], S[i]}, i + 1}); // i+1 because meeting numbers start from 1
        }
        
        // Sort based on finish time
        // If finish times are equal, sort by start time
        sort(meetings.begin(), meetings.end());
        
        vector<int> result;
        // Add first meeting
        result.push_back(meetings[0].second);
        int lastFinishTime = meetings[0].first.first;
        
        // Check remaining meetings
        for(int i = 1; i < N; i++) {
            // If current meeting's start time is strictly greater than last finish time
            if(meetings[i].first.second > lastFinishTime) {
                result.push_back(meetings[i].second);
                lastFinishTime = meetings[i].first.first;
            }
        }
        
        // Sort result to get meeting numbers in ascending order
        sort(result.begin(), result.end());
        
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends