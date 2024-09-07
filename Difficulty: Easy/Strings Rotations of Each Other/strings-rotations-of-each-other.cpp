//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
 public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1, string s2)
    {
        // If lengths of the strings are not the same, they cannot be rotations.
        if (s1.length() != s2.length()) {
            return false;
        }
        
        // Concatenate s1 with itself and check if s2 is a substring of this concatenated string.
        string concatenated = s1 + s1;
        
        // If s2 is a substring of concatenated s1, then it is a rotation.
        return (concatenated.find(s2) != string::npos);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends