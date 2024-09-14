//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S) {
        // If the sum of digits S is 0 and N is greater than 1, it is impossible to form such a number.
        if (S == 0 && N > 1) return "-1";
        
        // If the sum of digits S is greater than the maximum possible sum for N digits, it is impossible.
        if (S > 9 * N) return "-1";

        // String to store the result.
        string result = "";

        // Loop over each digit position.
        for (int i = 0; i < N; i++) {
            // Select the largest possible digit for the current position.
            if (S >= 9) {
                result += '9';
                S -= 9;
            } else {
                // If the sum left is less than 9, use that as the next digit.
                result += (char)(S + '0');
                S = 0;  // Set S to 0 since we've used up the remaining sum.
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends