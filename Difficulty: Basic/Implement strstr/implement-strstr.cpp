//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x) {
    int n = s.size();   // Length of the main string
    int m = x.size();   // Length of the substring
    
    // Iterate over 's' and check substrings starting from each index
    for (int i = 0; i <= n - m; i++) {
        int j;
        
        // Check if the substring of 's' starting at index 'i' matches 'x'
        for (j = 0; j < m; j++) {
            if (s[i + j] != x[j]) {
                break;  // If any character doesn't match, break out of the loop
            }
        }
        
        // If the entire substring matches, return the starting index
        if (j == m) {
            return i;
        }
    }
    
    // If no match is found, return -1
    return -1;
}