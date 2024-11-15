//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    const int MOD = 1000000007;

    // Function to perform modular exponentiation
    long long powerMod(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) { // If exp is odd, multiply the base with the result
                result = (result * base) % mod;
            }
            base = (base * base) % mod; // Square the base
            exp /= 2; // Divide the exponent by 2
        }
        return result;
    }

    // Function to find the Nth term of the GP
    int Nth_term(int A, int R, int N) {
        // Calculate R^(N-1) % MOD
        long long power = powerMod(R, N - 1, MOD);
        // Calculate the Nth term: (A * power) % MOD
        long long nthTerm = (A * power) % MOD;
        return nthTerm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, r, n;
		cin >> a >> r >> n;
		Solution ob;
		int ans = ob.Nth_term(a, r, n);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends