//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
public:
    long long countPairs(int n, int arr[], int k) {
        vector<long long> freq(k, 0);

        // Count frequencies of each modulo class
        for (int i = 0; i < n; ++i) {
            freq[arr[i] % k]++;
        }

        long long count = 0;

        // For each class, add combinations C(f, 2)
        for (int i = 0; i < k; ++i) {
            if (freq[i] > 1) {
                count += (freq[i] * (freq[i] - 1)) / 2;
            }
        }

        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends