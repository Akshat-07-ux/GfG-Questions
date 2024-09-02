//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
public:
    // Function to find all unique quadruples that sum up to the given target k.
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        vector<vector<int>> result;
        int n = arr.size();

        // Sort the array to use two-pointer technique
        sort(arr.begin(), arr.end());

        // Use a set to store unique quadruples
        set<vector<int>> quadruples;

        // First two loops to fix the first and second elements
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                // Two-pointer approach for the remaining two elements
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    int sum = arr[i] + arr[j] + arr[left] + arr[right];

                    if (sum == k) {
                        // Store the quadruple in a temporary vector
                        vector<int> quad = {arr[i], arr[j], arr[left], arr[right]};
                        quadruples.insert(quad);
                        left++;
                        right--;
                    } else if (sum < k) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        // Convert set of quadruples to a vector of vectors
        for (auto &quad : quadruples) {
            result.push_back(quad);
        }

        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends