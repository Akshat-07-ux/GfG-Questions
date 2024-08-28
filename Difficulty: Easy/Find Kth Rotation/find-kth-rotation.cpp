//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
 public:
    int findKRotation(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if the mid element is the smallest
            if (mid > 0 && arr[mid] < arr[mid - 1]) {
                return mid;
            }

            // Check if the array is already sorted
            if (arr[low] <= arr[high]) {
                return low;
            }

            // Decide which part to search
            if (arr[mid] >= arr[low]) {
                // If mid element is greater than or equal to low element,
                // then the rotation point is in the right half
                low = mid + 1;
            } else {
                // If mid element is less than low element,
                // then the rotation point is in the left half
                high = mid - 1;
            }
        }

        return 0; // This line should not be reached if input constraints are met
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
// } Driver Code Ends