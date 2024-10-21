//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    const int MOD = 1e9 + 7;
    
    // Function to calculate power with modulo
    long long mod_pow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countgroup(vector<int>& arr) {
        int n = arr.size();
        int totalXOR = 0;
        
        // Find total XOR of all elements
        for (int num : arr) {
            totalXOR ^= num;
        }
        
        // If the total XOR is non-zero, no valid partition
        if (totalXOR != 0) {
            return 0;
        }
        
        // If total XOR is zero, number of valid splits is 2^(n-1) - 1
        long long result = mod_pow(2, n - 1, MOD) - 1;
        if (result < 0) {
            result += MOD;
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends