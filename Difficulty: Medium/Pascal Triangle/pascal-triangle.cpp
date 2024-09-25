//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        const long long MOD = 1000000007;
        vector<long long> row(n);  // Create a vector to store the nth row

        row[0] = 1;  // First element is always 1

        // Compute each element using the relation element(i) = element(i-1) * (n-i) / i
        for (int i = 1; i < n; i++) {
            row[i] = (row[i - 1] * (n - i)) % MOD;  // Multiply previous element by (n-i)
            row[i] = (row[i] * modInverse(i, MOD)) % MOD;  // Multiply by modular inverse of i
        }

        return row;
    }

    // Function to compute modular inverse using Fermat's little theorem
    long long modInverse(long long a, long long m) {
        return power(a, m - 2, m);
    }

    // Function to compute (base^exponent) % mod
    long long power(long long base, long long exp, long long mod) {
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
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends