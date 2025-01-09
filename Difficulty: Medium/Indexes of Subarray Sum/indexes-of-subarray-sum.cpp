//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int left = 0;
        int currentSum = 0;

        for (int right = 0; right < arr.size(); right++) {
            currentSum += arr[right];  // Expand the window by adding the right element
            
            // Shrink the window until currentSum is less than or equal to target
            while (currentSum > target && left <= right) {
                currentSum -= arr[left];
                left++;
            }

            // If a subarray with the target sum is found, return its 1-based indices
            if (currentSum == target) {
                return {left + 1, right + 1};
            }
        }

        // If no such subarray is found, return [-1]
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends