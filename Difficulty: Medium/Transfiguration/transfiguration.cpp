//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int transfigure(string A, string B) {
        if (A.length() != B.length())
            return -1;

        // Frequency count to validate transformation
        vector<int> count(256, 0);
        for (char ch : A) count[ch]++;
        for (char ch : B) count[ch]--;

        for (int c : count) {
            if (c != 0) return -1; // Not the same characters
        }

        // Pointers starting from end of both strings
        int i = A.length() - 1;
        int j = B.length() - 1;

        int res = 0;

        while (i >= 0) {
            // If A[i] and B[j] match, move both
            if (A[i] == B[j]) {
                j--;
            } else {
                // Else, we need to move A[i] to front later
                res++;
            }
            i--;
        }

        return res;
    }
};


//{ Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends