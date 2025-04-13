//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int sumExists(int arr[], int N, int sum);

// } Driver Code Ends

// User function Template for C++

int sumExists(int arr[], int N, int sum) {
    std::unordered_set<int> seen;

    for (int i = 0; i < N; ++i) {
        int complement = sum - arr[i];

        if (seen.find(complement) != seen.end()) {
            return 1; // Found a pair
        }

        seen.insert(arr[i]);
    }

    return 0; // No pair found
}


//{ Driver Code Starts.

int main() {

    int testcases;
    cin >> testcases;
    while (testcases--) {
        int N;
        cin >> N;

        int arr[N];

        for (int i = 0; i < N; i++) cin >> arr[i];
        int sum;
        cin >> sum;

        cout << sumExists(arr, N, sum) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends