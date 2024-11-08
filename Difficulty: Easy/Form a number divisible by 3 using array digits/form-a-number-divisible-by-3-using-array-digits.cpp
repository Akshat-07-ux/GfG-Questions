//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isPossible(int N, int arr[]) {
        int sumOfDigits = 0;

        // Iterate through each number in the array
        for (int i = 0; i < N; ++i) {
            int num = arr[i];

            // Extract digits of the current number
            while (num > 0) {
                sumOfDigits += num % 10;
                num /= 10;
            }
        }

        // Check if the sum of all digits is divisible by 3
        return (sumOfDigits % 3 == 0) ? 1 : 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends