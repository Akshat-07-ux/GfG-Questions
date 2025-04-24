//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        int result = 0;
        
        // For each bit position (0 to 31 for 32-bit int)
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            
            for (int num : arr) {
                if (num & (1 << i)) {
                    sum++;
                }
            }
            
            // If sum is not divisible by 3, this bit is set in the unique number
            if (sum % 3) {
                result |= (1 << i);
            }
        }

        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends