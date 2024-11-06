//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    // Function to check if a string is a pangram or not.
    bool checkPangram(string s) {
        // Array to mark the presence of each letter
        bool letters[26] = {false};

        // Traverse the string
        for (char c : s) {
            // Convert uppercase to lowercase
            if (isalpha(c)) {
                c = tolower(c);
                letters[c - 'a'] = true;
            }
        }

        // Check if all letters are present
        for (bool present : letters) {
            if (!present) return false;
        }

        return true;
    }
};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    
cout << "~" << "\n";
}
    return(0);
}

// } Driver Code Ends