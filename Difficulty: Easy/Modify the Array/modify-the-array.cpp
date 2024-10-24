//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return arr;

        // Step 1: Modify the array by doubling current number and setting next to 0 if both are equal
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] != 0 && arr[i] == arr[i + 1]) {
                arr[i] *= 2;
                arr[i + 1] = 0;
            }
        }

        // Step 2: Rearrange the array to shift all non-zero elements to the front
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] != 0) {
                arr[index++] = arr[i];
            }
        }

        // Step 3: Fill the remaining elements with 0
        while (index < n) {
            arr[index++] = 0;
        }

        return arr;
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
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends