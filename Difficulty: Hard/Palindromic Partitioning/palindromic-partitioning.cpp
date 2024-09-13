//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // Function to determine the minimum cuts needed for palindrome partitioning
    int palindromicPartition(string str) {
        int n = str.length();
        
        // Table to store whether str[i..j] is a palindrome
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        
        // DP table to store the minimum number of cuts needed
        vector<int> cuts(n, 0);
        
        // Precompute whether substrings are palindromes
        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true; // Single characters are palindromes
        }
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (str[i] == str[j]) {
                    if (len == 2) {
                        isPalindrome[i][j] = true; // Two-character strings
                    } else {
                        isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                    }
                }
            }
        }
        
        // Fill the cuts[] array
        for (int i = 0; i < n; i++) {
            if (isPalindrome[0][i]) {
                cuts[i] = 0; // No cut needed if the whole substring is a palindrome
            } else {
                cuts[i] = i; // Maximum cuts = i (cut at every character)
                for (int j = 0; j < i; j++) {
                    if (isPalindrome[j + 1][i] && cuts[j] + 1 < cuts[i]) {
                        cuts[i] = cuts[j] + 1;
                    }
                }
            }
        }
        
        return cuts[n - 1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends