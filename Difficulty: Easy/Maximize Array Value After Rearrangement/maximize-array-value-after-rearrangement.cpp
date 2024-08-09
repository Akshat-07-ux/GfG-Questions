//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    int Maximize(std::vector<int> &arr) {
        int n = arr.size();
        // Sort the array
        std::sort(arr.begin(), arr.end());

        // Initialize the result
        long long result = 0;
        long long mod = 1000000007;

        // Calculate the maximum value of ∑arr[i]*i
        for (int i = 0; i < n; i++) {
            result = (result + (arr[i] * 1LL * i) % mod) % mod;
        }

        return result;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends