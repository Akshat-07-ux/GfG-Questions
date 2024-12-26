//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:	
    int distinctSubsequences(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<int> dp(n + 1, 0); // dp[i] stores the number of distinct subsequences of the first i characters
        dp[0] = 1; // Base case: empty string has one subsequence: ""

        vector<int> lastOccurrence(26, -1); // Tracks last occurrence of each character

        for (int i = 1; i <= n; ++i) {
            dp[i] = (2 * dp[i - 1]) % MOD; // Double the subsequences of the previous substring

            char currentChar = s[i - 1];
            int charIndex = currentChar - 'a';

            if (lastOccurrence[charIndex] != -1) {
                dp[i] = (dp[i] - dp[lastOccurrence[charIndex]] + MOD) % MOD;
                // Subtract subsequences ending before the last occurrence of currentChar to avoid duplicates
            }

            lastOccurrence[charIndex] = i - 1; // Update the last occurrence of currentChar
        }

        return dp[n];
    }
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends