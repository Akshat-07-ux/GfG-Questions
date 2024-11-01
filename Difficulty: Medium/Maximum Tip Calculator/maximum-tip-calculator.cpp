//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
 public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // Create a vector of pairs to store the difference in tips and the index
        vector<pair<int, int>> diff(n);
        
        // Calculate the tip difference between A and B for each order
        for (int i = 0; i < n; i++) {
            diff[i] = {abs(arr[i] - brr[i]), i};
        }
        
        // Sort in descending order of tip difference
        sort(diff.begin(), diff.end(), greater<pair<int, int>>());
        
        // Initialize variables to track orders assigned to A and B
        long long totalTip = 0;
        int aCount = 0, bCount = 0;
        
        // Iterate through the sorted differences
        for (auto &p : diff) {
            int index = p.second;
            
            // Prioritize the order for the waiter with fewer current assignments
            // while respecting the maximum order constraints
            if ((aCount < x && arr[index] > brr[index]) || 
                (bCount >= y && arr[index] <= brr[index])) {
                totalTip += arr[index];
                aCount++;
            } else {
                totalTip += brr[index];
                bCount++;
            }
        }
        
        return totalTip;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends