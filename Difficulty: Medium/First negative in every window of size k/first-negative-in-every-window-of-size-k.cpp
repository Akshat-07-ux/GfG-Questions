//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> result;  // To store the result
    deque<long long> dq;       // To store indices of negative numbers

    // Process the first window of size K
    for (long long i = 0; i < K; i++) {
        if (A[i] < 0) {
            dq.push_back(i);  // Add index of negative number
        }
    }

    // Process the rest of the windows
    for (long long i = K; i < N; i++) {
        // For the previous window, if there was a negative number, add it to result
        if (!dq.empty()) {
            result.push_back(A[dq.front()]);
        } else {
            result.push_back(0);  // No negative number in the previous window
        }

        // Remove elements that are out of this window
        while (!dq.empty() && dq.front() < i - K + 1) {
            dq.pop_front();
        }

        // Add the current element if it is negative
        if (A[i] < 0) {
            dq.push_back(i);
        }
    }

    // Add the result for the last window
    if (!dq.empty()) {
        result.push_back(A[dq.front()]);
    } else {
        result.push_back(0);
    }

    return result;
}