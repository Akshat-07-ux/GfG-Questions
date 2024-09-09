//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(vector<long long>& arr) {
        int n = arr.size();
        stack<int> s;
        long long maxArea = 0;
        int i = 0;
        
        while (i < n) {
            if (s.empty() || arr[s.top()] <= arr[i]) {
                s.push(i++);
            } else {
                int top = s.top();
                s.pop();
                long long area = arr[top] * (s.empty() ? i : i - s.top() - 1);
                maxArea = max(maxArea, area);
            }
        }
        
        while (!s.empty()) {
            int top = s.top();
            s.pop();
            long long area = arr[top] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends