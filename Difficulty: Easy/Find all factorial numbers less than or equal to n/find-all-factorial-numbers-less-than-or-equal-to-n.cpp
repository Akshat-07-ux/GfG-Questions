//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
 public:
    vector<long long> factorialNumbers(long long n) {
        vector<long long> result;
        long long fact = 1;  // First factorial (0! = 1)
        int i = 1;
        
        // Keep calculating factorial and adding it to the result vector until it exceeds n
        while (fact <= n) {
            result.push_back(fact);
            i++;  // Increment i to get the next factorial
            fact *= i;  // fact becomes i!
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends