//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
   public:
    int findElement(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) return -1;  // At least 3 elements are needed to have left and right sides

        // Step 1: Create leftMax array
        vector<int> leftMax(n);
        leftMax[0] = INT_MIN; // No elements on the left of arr[0]
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], arr[i - 1]);
        }

        // Step 2: Create rightMin array
        vector<int> rightMin(n);
        rightMin[n - 1] = INT_MAX; // No elements on the right of arr[n-1]
        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i + 1], arr[i + 1]);
        }

        // Step 3: Traverse the array and find the element that satisfies the condition
        for (int i = 1; i < n - 1; i++) {
            if (leftMax[i] < arr[i] && rightMin[i] > arr[i]) {
                return arr[i];
            }
        }

        // If no such element is found
        return -1;
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
        Solution ob;
        int ans = ob.findElement(arr);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends