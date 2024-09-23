//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

const int MOD = 1e9 + 7;

class Solution {
public:
    // Function to perform modular exponentiation
    long long modExp(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    // Function to compute nCr % MOD
    long long nCrMod(long long n, long long r, long long mod) {
        if (r > n) return 0;
        long long num = 1, den = 1;
        
        // Calculate n! / (r! * (n-r)!)
        for (long long i = 0; i < r; i++) {
            num = (num * (n - i)) % mod;
            den = (den * (i + 1)) % mod;
        }
        
        // Return result using modular inverse
        return (num * modExp(den, mod - 2, mod)) % mod;
    }

    long long numberOfPaths(int M, int N) {
        // We need to compute C(M + N - 2, min(M-1, N-1)) % MOD
        int totalMoves = M + N - 2;
        int downMoves = min(M - 1, N - 1);
        return nCrMod(totalMoves, downMoves, MOD);
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends