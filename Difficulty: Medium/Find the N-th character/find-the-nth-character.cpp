//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        int index = n;
        int flipCount = 0;

        // Traverse back through r levels to find the original character
        for (int i = r; i > 0; --i) {
            // At each iteration, every bit expands into 2 bits
            // So the previous index is halved
            if (index % 2 == 1) {
                // If we are in the second part (i.e. from a '1' -> '10' or '0' -> '01'), we flip
                flipCount++;
            }
            index /= 2;
        }

        char original = s[index];
        if (flipCount % 2 == 0) {
            return original;
        } else {
            return original == '0' ? '1' : '0';
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends