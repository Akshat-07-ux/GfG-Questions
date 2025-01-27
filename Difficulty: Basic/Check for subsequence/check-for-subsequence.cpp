//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std; 

// } Driver Code Ends

class Solution{
public:
    bool isSubSequence(string A, string B) {
        int n = A.length();
        int m = B.length();
        
        int i = 0, j = 0; // Two pointers: i for A, j for B
        
        // Traverse both strings
        while (i < n && j < m) {
            // If characters match, move pointer of A
            if (A[i] == B[j]) {
                i++;
            }
            // Always move pointer of B
            j++;
        }
        
        // If all characters of A were found in B in order
        return i == n;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;  
        Solution ob;
        if(ob.isSubSequence(A,B))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    
cout << "~" << "\n";
}
    return 0; 
} 

// } Driver Code Ends