//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    bool check_elements(int arr[], int n, int A, int B) {
        // Calculate the number of elements in the range [A, B]
        int rangeSize = B - A + 1;

        // Create a boolean array to track which elements are found
        bool found[rangeSize] = {false};

        // Traverse the array and mark the elements in the range as found
        for (int i = 0; i < n; ++i) {
            if (arr[i] >= A && arr[i] <= B) {
                found[arr[i] - A] = true;
            }
        }

        // Check if all elements in the range are found
        for (int i = 0; i < rangeSize; ++i) {
            if (!found[i]) {
                return false;
            }
        }

        return true;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, A, B;
        cin >> n >> A >> B;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        Solution ob;
        if (ob.check_elements(a, n, A, B))
            cout << "True";
        else
            cout << "False";

        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends