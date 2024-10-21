//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
public:
    string removeConsecutiveCharacter(string S) {
        string result = ""; // To store the final string without consecutive duplicates
        
        for (int i = 0; i < S.length(); i++) {
            // Only add character if it's different from the previous one
            if (i == 0 || S[i] != S[i - 1]) {
                result += S[i];
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends