//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> rotate(int n, int d) {
        // Ensure D is within the range of 0 to 15 by using modulo
        d = d % 16;

        // 16-bit mask to restrict to 16 bits after rotation
        int mask = (1 << 16) - 1;

        // Left rotation
        int leftRotate = ((n << d) | (n >> (16 - d))) & mask;

        // Right rotation
        int rightRotate = ((n >> d) | (n << (16 - d))) & mask;

        // Return results in a vector
        return {leftRotate, rightRotate};
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    
cout << "~" << "\n";
}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends