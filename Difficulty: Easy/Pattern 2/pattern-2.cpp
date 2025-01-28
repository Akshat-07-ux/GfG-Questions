//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
public:
    void printTriangle(int n) {
        // Outer loop for the number of rows
        for (int i = 1; i <= n; i++) {
            // Inner loop to print stars in each row
            for (int j = 1; j <= i; j++) {
                cout << "* ";
            }
            // Move to the next line after each row
            cout << endl;
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
        ob.printTriangle(n);
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends