//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void printTillN(int n) {
        // Base case: if n is 0, return
        if (n == 0) {
            return;
        }
        
        // Recursive call for numbers till n-1
        printTillN(n - 1);
        
        // Print the current number
        std::cout << n << " ";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        ob.printTillN(N);
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends