//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string isPrime(int n) {
        // 1 is not a prime number
        if (n <= 1) {
            return "No";
        }

        // Check divisibility from 2 to sqrt(n)
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return "No"; // Not prime if divisible by any number
            }
        }

        // If no divisors were found, the number is prime
        return "Yes";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        Solution obj;
        string res = obj.isPrime(n);

        cout << res << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends