//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int TotalWays(int N) {
        const int MOD = 1000000007;

        // Base cases for N = 1
        if (N == 1) return 4;

        // Initialize variables for dynamic programming
        long long prev = 2; // Ways for N = 1
        long long curr = 3; // Ways for N = 2

        // Iterate from 3 to N
        for (int i = 3; i <= N; i++) {
            long long temp = (prev + curr) % MOD;
            prev = curr;
            curr = temp;
        }

        // Result is (ways_on_one_side)^2 % MOD
        return (curr * curr) % MOD;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends