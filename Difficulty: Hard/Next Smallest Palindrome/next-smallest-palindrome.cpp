//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    vector<int> generateNextPalindrome(int num[], int n) {
        vector<int> result(num, num + n);
        
        // Special case for single digit
        if (n == 1) {
            if (num[0] == 9) {
                return {1, 1};
            }
            result[0] = num[0] + 1;
            return result;
        }
        
        // Step 1: Find the middle point
        int mid = n / 2;
        bool leftSmaller = false;
        
        // Step 2: Compare left and right half
        int i = mid - 1;
        int j = (n % 2) ? mid + 1 : mid;
        
        // Skip the same digits
        while (i >= 0 && result[i] == result[j]) {
            i--;
            j++;
        }
        
        // Check if left side is smaller
        if (i < 0 || result[i] < result[j]) {
            leftSmaller = true;
        }
        
        // Step 3: Mirror left half to right half
        i = mid - 1;
        j = (n % 2) ? mid + 1 : mid;
        
        while (i >= 0) {
            result[j] = result[i];
            i--;
            j++;
        }
        
        // Step 4: Handle the case when we need to increment
        if (leftSmaller) {
            int carry = 1;
            i = mid - 1;
            
            // If n is odd, update the middle digit
            if (n % 2 == 1) {
                result[mid] += carry;
                carry = result[mid] / 10;
                result[mid] %= 10;
                j = mid + 1;
            } else {
                j = mid;
            }
            
            // Handle carry and update digits
            while (i >= 0) {
                result[i] += carry;
                carry = result[i] / 10;
                result[i] %= 10;
                result[j] = result[i];
                i--;
                j++;
            }
            
            // Handle the case when we need an extra digit
            if (carry) {
                vector<int> newResult(n + 1, 0);
                newResult[0] = 1;
                newResult[n] = 1;
                return newResult;
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends