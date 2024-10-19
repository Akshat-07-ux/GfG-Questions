//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    typedef long long int ll;

    long long int minValue(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        
        // Sort arr1 in ascending order
        sort(arr1.begin(), arr1.end());
        
        // Sort arr2 in descending order
        sort(arr2.begin(), arr2.end(), greater<int>());
        
        ll result = 0;
        
        // Compute the sum of products of corresponding elements
        for (int i = 0; i < n; i++) {
            result += (ll)arr1[i] * (ll)arr2[i];
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
        vector<int> arr1, arr2;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr1.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long int ans = ob.minValue(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends