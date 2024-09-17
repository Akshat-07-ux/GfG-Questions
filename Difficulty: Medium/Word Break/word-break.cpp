//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    // Function to check if the string can be segmented into dictionary words
    int wordBreak(int n, string s, vector<string>& dictionary) {
        // Create a set for quick look-up of dictionary words
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        // dp[i] will be true if the substring s[0..i-1] can be segmented
        vector<bool> dp(s.size() + 1, false);
        
        // Empty string can always be segmented
        dp[0] = true;

        // Iterate over the string and fill dp array
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                // If substring s[j..i-1] is in the dictionary and dp[j] is true
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;  // No need to check further once dp[i] is true
                }
            }
        }

        // Return 1 if the entire string can be segmented, otherwise 0
        return dp[s.size()] ? 1 : 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends