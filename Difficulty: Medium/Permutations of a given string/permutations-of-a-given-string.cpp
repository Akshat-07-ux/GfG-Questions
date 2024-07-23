//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<string> find_permutation(string S) {
        // Vector to store the permutations
        vector<string> permutations;
        
        // Sort the string to get the lexicographically smallest permutation
        sort(S.begin(), S.end());
        
        // Add the first permutation
        permutations.push_back(S);
        
        // Generate the rest of the permutations
        while (next_permutation(S.begin(), S.end())) {
            permutations.push_back(S);
        }
        
        return permutations;
    }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends