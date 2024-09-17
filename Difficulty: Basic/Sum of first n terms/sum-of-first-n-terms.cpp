//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
    public:
    long long sumOfSeries(long long n) {
        // Using the formula for the sum of cubes of first n natural numbers
        long long sum = (n * (n + 1)) / 2;  // Sum of first n natural numbers
        return sum * sum;  // Square of the sum
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
        cout << ob.sumOfSeries(N) << "\n";
    }
}
// } Driver Code Ends