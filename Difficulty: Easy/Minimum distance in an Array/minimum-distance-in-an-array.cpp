//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    int minDist(int a[], int n, int x, int y) {
        int min_distance = INT_MAX;
        int last_x = -1, last_y = -1;

        // Traverse the array and keep track of the latest occurrences of x and y
        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                last_x = i;
                // If y has been encountered before, update the minimum distance
                if (last_y != -1) {
                    min_distance = std::min(min_distance, last_x - last_y);
                }
            } else if (a[i] == y) {
                last_y = i;
                // If x has been encountered before, update the minimum distance
                if (last_x != -1) {
                    min_distance = std::min(min_distance, last_y - last_x);
                }
            }
        }

        // If either x or y was never found, return -1
        if (last_x == -1 || last_y == -1) {
            return -1;
        }

        return min_distance;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends