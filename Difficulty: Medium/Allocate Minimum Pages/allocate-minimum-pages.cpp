//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // If there are more students than books, it's not possible to allocate
        if (m > n) return -1;

        // Calculate the total number of pages and find the maximum pages in a single book
        long long sum = 0;
        long long max_pages = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            max_pages = max(max_pages, (long long)arr[i]);
        }

        // Binary search for the minimum maximum number of pages
        long long low = max_pages;
        long long high = sum;
        long long result = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(arr, n, m, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }

private:
    // Helper function to check if it is possible to allocate books with max pages <= mid
    bool isPossible(int arr[], int n, int m, long long mid) {
        int student_count = 1;
        long long current_sum = 0;

        for (int i = 0; i < n; ++i) {
            if (current_sum + arr[i] > mid) {
                student_count++;
                current_sum = arr[i];
                if (student_count > m) return false;
            } else {
                current_sum += arr[i];
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
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends