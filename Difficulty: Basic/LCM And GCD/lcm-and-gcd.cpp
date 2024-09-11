//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to calculate the GCD using Euclid's algorithm
    long long gcd(long long A, long long B) {
        while (B != 0) {
            long long temp = B;
            B = A % B;
            A = temp;
        }
        return A;
    }
    
    vector<long long> lcmAndGcd(long long A, long long B) {
        long long gcdValue = gcd(A, B);            // Calculate GCD
        long long lcmValue = (A * B) / gcdValue;   // Calculate LCM using the relation
        return {lcmValue, gcdValue};               // Return both values in a vector
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends