//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
   public:
    // Function to find the minimum indexed character.
    int minIndexChar(string str, string patt) {
        // Create a set to store characters of patt.
        unordered_set<char> pattSet(patt.begin(), patt.end());
        
        // Traverse str and find the first character that exists in pattSet.
        for (int i = 0; i < str.size(); i++) {
            if (pattSet.find(str[i]) != pattSet.end()) {
                return i; // Return the index of the first matching character.
            }
        }
        
        // Return -1 if no common character is found.
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends