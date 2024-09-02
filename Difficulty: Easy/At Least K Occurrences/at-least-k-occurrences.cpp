//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    int firstElementKTime(int n, int k, int arr[]) {
        // Create a hash map to store the frequency of each element
        std::unordered_map<int, int> frequencyMap;
        
        // Traverse the array
        for (int i = 0; i < n; i++) {
            // Increment the count of the current element
            frequencyMap[arr[i]]++;
            
            // Check if this element has reached the frequency k
            if (frequencyMap[arr[i]] == k) {
                return arr[i];
            }
        }
        
        // If no element found with frequency k, return -1
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.firstElementKTime(n, k, a) << endl;
    }

    return 0;
}
// } Driver Code Ends