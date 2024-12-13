//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    int DivisibleByEight(string s) {
        // Get the length of the string
        int n = s.size();
        
        // Consider the last 3 digits or less if the length is smaller
        string lastThreeDigits = s.substr(max(0, n - 3), 3);
        
        // Convert the last three digits to an integer
        int num = stoi(lastThreeDigits);
        
        // Check divisibility by 8
        if (num % 8 == 0) {
            return 1;  // Divisible by 8
        }
        return -1;  // Not divisible by 8
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends