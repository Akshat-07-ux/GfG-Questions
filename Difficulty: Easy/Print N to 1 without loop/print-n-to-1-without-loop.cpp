//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    void printNos(int N) {
        // Base case: if N is less than or equal to 0, stop the recursion
        if (N < 1) return;
        
        // Print the current value of N
        cout << N << " ";
        
        // Recursively call printNos for N-1
        printNos(N - 1);
    }
};

//{ Driver Code Starts.
/* Driver program to test printNos */
int main() {
    int T;

    // taking testcases
    cin >> T;

    while (T--) {
        int N;

        // input N
        cin >> N;
        Solution ob;
        // calling printNos() function
        ob.printNos(N);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends