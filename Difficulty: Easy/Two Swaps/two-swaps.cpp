//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    bool checkSorted(std::vector<int> &arr) {
        int n = arr.size();
        
        // Create a copy of the array and sort it
        std::vector<int> sortedArr = arr;
        std::sort(sortedArr.begin(), sortedArr.end());
        
        // Find the indices where arr differs from sortedArr
        std::vector<int> mismatchIndices;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] != sortedArr[i]) {
                mismatchIndices.push_back(i);
            }
        }
        
        // If no mismatch, array is already sorted
        if (mismatchIndices.size() == 0) {
            return true; // Already sorted
        }
        
        // If more than 4 mismatches, it cannot be sorted in exactly 2 swaps
        if (mismatchIndices.size() != 4) {
            return false;
        }
        
        // Check if we can fix the array with two swaps
        // Swap 1st and 4th mismatch and 2nd and 3rd mismatch should fix the array
        std::swap(arr[mismatchIndices[0]], arr[mismatchIndices[3]]);
        std::swap(arr[mismatchIndices[1]], arr[mismatchIndices[2]]);
        
        // Now check if arr is sorted
        return arr == sortedArr;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends