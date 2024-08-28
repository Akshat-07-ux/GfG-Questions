//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    // Function to check if the Pythagorean triplet exists or not
    bool checkTriplet(int arr[], int n) {
        // Step 1: Create a set to store squares of elements
        std::unordered_set<int> squares;
        
        // Step 2: Find the maximum element
        int max_element = *std::max_element(arr, arr + n);
        
        // Step 3: Create a boolean array to mark present elements
        std::vector<bool> present(max_element + 1, false);
        
        // Step 4: Iterate through the array
        for (int i = 0; i < n; i++) {
            // Mark the element as present
            present[arr[i]] = true;
            
            // Add square of the element to the set
            squares.insert(arr[i] * arr[i]);
        }
        
        // Step 5: Check for Pythagorean triplet
        for (int i = 1; i <= max_element; i++) {
            if (!present[i]) continue;
            
            for (int j = i + 1; j <= max_element; j++) {
                if (!present[j]) continue;
                
                // Check if i^2 + j^2 is in the set of squares
                if (squares.find(i*i + j*j) != squares.end()) {
                    return true;
                }
            }
        }
        
        // No Pythagorean triplet found
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends