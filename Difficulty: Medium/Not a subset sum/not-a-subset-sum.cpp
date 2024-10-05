//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    long long findSmallest(vector<int> &arr) {
        long long smallest = 1;  // Smallest number we cannot form initially
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > smallest) {
                break;  // If current element is larger than the smallest number we can't form
            }
            smallest += arr[i];  // Otherwise, we can form up to `smallest + arr[i]`
        }
        return smallest;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        auto ans = ob.findSmallest(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends