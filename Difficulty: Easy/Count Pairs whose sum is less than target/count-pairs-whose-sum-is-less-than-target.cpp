//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int>& arr, int target) {
        // Sort the array first
        sort(arr.begin(), arr.end());
        
        int left = 0, right = arr.size() - 1;
        int count = 0;

        // Use two pointers to find pairs with sum less than target
        while (left < right) {
            if (arr[left] + arr[right] < target) {
                // All pairs between left and right will be valid
                count += (right - left);
                left++;
            } else {
                right--;
            }
        }
        return count;
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends