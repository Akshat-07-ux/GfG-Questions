//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    // Function to find the first occurrence of X
    int firstOccurrence(int arr[], int n, int x) {
        int low = 0, high = n - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                result = mid;
                high = mid - 1; // Look on the left side for the first occurrence
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }

    // Function to find the last occurrence of X
    int lastOccurrence(int arr[], int n, int x) {
        int low = 0, high = n - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                result = mid;
                low = mid + 1; // Look on the right side for the last occurrence
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }

    // Function to count occurrences of X
    int count(int arr[], int n, int x) {
        int first = firstOccurrence(arr, n, x);
        if (first == -1) {
            return 0; // X is not present in the array
        }
        int last = lastOccurrence(arr, n, x);
        return last - first + 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends