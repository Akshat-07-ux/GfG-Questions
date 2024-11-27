//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long countPairs(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        
        // Precompute counts for special values in arr2
        int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
        for (int y : arr2) {
            if (y == 1) count1++;
            else if (y == 2) count2++;
            else if (y == 3) count3++;
            else if (y == 4) count4++;
        }
        
        long long result = 0;
        for (int x : arr1) {
            if (x == 1) {
                continue; // (1, y) does not satisfy x^y > y^x unless y == 1
            }

            // Binary search to count valid pairs
            int pos = upper_bound(arr2.begin(), arr2.end(), x) - arr2.begin();
            result += arr2.size() - pos;
            
            // Special cases:
            if (x == 2) {
                result -= count4 + count3; // For (2,3), (2,4) -> 2^y <= y^2
                result += count1;          // For (2,1) -> 2^1 > 1^2
            } else if (x == 3) {
                result += count2;          // For (3,2) -> 3^2 > 2^3
                result += count1;          // For (3,1) -> 3^1 > 1^3
            } else {
                result += count1;          // For (x,1) -> x^1 > 1^x
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr1, arr2;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the first array elements
        stringstream ss1(input1);
        int number;
        while (ss1 >> number) {
            arr1.push_back(number);
        }

        getline(cin, input2); // Read the entire line for the second array elements
        stringstream ss2(input2);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        long long ans = ob.countPairs(arr1, arr2);
        cout << ans << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends