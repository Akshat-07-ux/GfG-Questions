//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    // Custom comparator to order strings in a way that results in the largest concatenated number
    static bool compare(string &X, string &Y) {
        return X + Y > Y + X;
    }
    
    string printLargest(int n, vector<string> &arr) {
        // Sort the array with the custom comparator
        sort(arr.begin(), arr.end(), compare);
        
        // Edge case: If the largest number is "0", then the entire result should be "0"
        if (arr[0] == "0") {
            return "0";
        }
        
        // Concatenate the sorted array to form the largest number
        string largestNumber;
        for (const string &num : arr) {
            largestNumber += num;
        }
        
        return largestNumber;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends