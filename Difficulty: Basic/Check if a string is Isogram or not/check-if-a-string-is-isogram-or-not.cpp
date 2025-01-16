//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
  public:
    // Function to check if a string is Isogram or not.
    bool isIsogram(string s)
    {
        // Use a hash set to track seen characters
        unordered_set<char> seen;

        // Traverse the string
        for (char ch : s) {
            // Check if the character is already in the set
            if (seen.find(ch) != seen.end()) {
                return false; // Duplicate found
            }
            // Add the character to the set
            seen.insert(ch);
        }

        // If no duplicates found, return true
        return true;
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
        Solution obj;
        cout<<obj.isIsogram(s)<<endl;
        
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends