//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
        long long int PowMod(long long int x, long long int n, long long int M) {
            long long int result = 1;  // Initialize result to 1

            // Ensure x is within the modulo range
            x = x % M;

            // Fast exponentiation loop
            while (n > 0) {
                // If n is odd, multiply the current x with result
                if (n % 2 == 1) {
                    result = (result * x) % M;
                }

                // Square x and reduce n by half
                x = (x * x) % M;
                n = n / 2;
            }

            return result;
        }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends