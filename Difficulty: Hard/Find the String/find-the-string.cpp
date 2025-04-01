//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++
class Solution
{
public:
    // Function to generate the De Bruijn sequence
    string findString(int n, int k) {
        string result;
        string start(n - 1, '0'); // Start with (n-1) zeroes
        unordered_set<string> visited;
        
        dfs(start, k, visited, result);
        result += start; // Append the starting sequence to close the cycle
        return result;
    }

private:
    void dfs(string node, int k, unordered_set<string>& visited, string& result) {
        for (int i = 0; i < k; i++) {
            string newNode = node + char('0' + i);
            if (!visited.count(newNode)) {
                visited.insert(newNode);
                dfs(newNode.substr(1), k, visited, result);
                result += char('0' + i);
            }
        }
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    
cout << "~" << "\n";
}
    return 0;
} 
// } Driver Code Ends