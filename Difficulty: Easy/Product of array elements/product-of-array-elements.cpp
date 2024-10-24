//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    long long int product(vector<int> &arr) {
        long long int mod = 1000000007;
        long long int result = 1;

        // Iterate through the array and compute the product under modulo
        for (int i = 0; i < arr.size(); i++) {
            result = (result * arr[i]) % mod;
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;

        cout << ob.product(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends