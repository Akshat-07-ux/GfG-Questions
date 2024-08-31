//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Create an unordered set to store elements of the first array
        std::unordered_set<int> elementsSet;
        
        // Insert all elements of the first array into the set
        for (int i = 0; i < n; ++i) {
            elementsSet.insert(a[i]);
        }
        
        // Initialize the count of common elements
        int count = 0;
        
        // Iterate through the second array
        for (int i = 0; i < m; ++i) {
            // Check if the element is present in the set
            if (elementsSet.find(b[i]) != elementsSet.end()) {
                // If present, it means it's a common element, increment the count
                ++count;
                // Remove the element from the set to avoid counting duplicates
                elementsSet.erase(b[i]);
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends