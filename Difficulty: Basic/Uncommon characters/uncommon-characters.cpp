//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
 public:
    string UncommonChars(string A, string B) {
        // Boolean arrays to track characters in A and B
        vector<bool> presentInA(26, false);
        vector<bool> presentInB(26, false);
        
        // Mark the presence of each character in string A
        for (char c : A) {
            presentInA[c - 'a'] = true;
        }
        
        // Mark the presence of each character in string B
        for (char c : B) {
            presentInB[c - 'a'] = true;
        }
        
        // Vector to store the uncommon characters
        string result;
        
        // Check for uncommon characters
        for (int i = 0; i < 26; i++) {
            // If character i is present in A or B, but not in both
            if (presentInA[i] != presentInB[i]) {
                result += (char)(i + 'a');
            }
        }
        
        // If no uncommon characters are found, return "-1"
        if (result.empty()) {
            return "-1";
        }
        
        // Return the uncommon characters (already sorted)
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
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends