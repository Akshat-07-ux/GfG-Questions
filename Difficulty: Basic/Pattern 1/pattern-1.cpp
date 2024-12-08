//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printSquare(int n) {
        // Loop through each row
        for (int i = 0; i < n; ++i) {
            // Loop through each column
            for (int j = 0; j < n; ++j) {
                cout << "*";
                if (j < n - 1) cout << " "; // Add space between stars except the last one in the row
            }
            cout << endl; // Move to the next line after printing a row
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printSquare(n);
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends