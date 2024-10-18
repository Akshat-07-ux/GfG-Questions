//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Sort the array first
        sort(arr, arr + n);
        
        long long count = 0;
        
        // Iterate over the array, fixing one element arr[i]
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;  // The second pointer starts from i + 1
            int k = n - 1;  // The third pointer starts from the last element
            
            // Use the two-pointer technique to find pairs
            while (j < k) {
                long long currentSum = arr[i] + arr[j] + arr[k];
                
                // If the sum of the triplet is smaller than the target sum
                if (currentSum < sum) {
                    // All elements between j and k form valid triplets
                    count += (k - j);
                    j++;  // Move the second pointer to the right to check for new triplets
                } else {
                    // If the sum is greater or equal, move the third pointer left to decrease the sum
                    k--;
                }
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
        int n;
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(n, sum, arr);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends