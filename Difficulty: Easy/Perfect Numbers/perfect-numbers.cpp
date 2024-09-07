//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int isPerfectNumber(long long N) {
        // Early return for 1, since 1 is not a perfect number
        if (N == 1) return 0;

        long long sum = 1; // 1 is a divisor for all numbers greater than 1

        // Find all divisors up to sqrt(N)
        for (long long i = 2; i * i <= N; ++i) {
            if (N % i == 0) {
                sum += i;
                if (i != N / i) {
                    sum += N / i; // Add both divisors
                }
            }
        }

        // Check if the sum of divisors (excluding N itself) equals N
        return sum == N ? 1 : 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends