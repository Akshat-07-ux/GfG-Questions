//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
public:
    long long max_sum(int a[], int n) {
        long long sum = 0;
        long long initial_sum = 0;
        
        // Calculate the sum of all elements and the initial sum of i*a[i]
        for (int i = 0; i < n; i++) {
            sum += a[i];
            initial_sum += (long long)i * a[i];
        }
        
        long long max_sum = initial_sum;
        long long current_sum = initial_sum;
        
        // Iterate through all rotations
        for (int i = 1; i < n; i++) {
            // Update the sum for the current rotation
            current_sum = current_sum - (sum - a[i-1]) + (long long)(n-1) * a[i-1];
            
            // Update max_sum if necessary
            max_sum = std::max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends