//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return n;
        
        int inc = 1, dec = 1;
        
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i-1]) {
                inc = dec + 1;
            } else if (arr[i] < arr[i-1]) {
                dec = inc + 1;
            }
            // If elements are equal, we don't update inc or dec
        }
        
        return max(inc, dec);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends