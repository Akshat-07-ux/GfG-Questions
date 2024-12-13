//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;

        // If the array is not rotated
        if (arr[low] <= arr[high])
            return arr[low];

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if mid element is the minimum
            if (mid > 0 && arr[mid] < arr[mid - 1])
                return arr[mid];

            // Check if the next element is the minimum
            if (mid < arr.size() - 1 && arr[mid] > arr[mid + 1])
                return arr[mid + 1];

            // Adjust the search range
            if (arr[mid] >= arr[low]) {
                // Minimum is in the right part
                low = mid + 1;
            } else {
                // Minimum is in the left part
                high = mid - 1;
            }
        }

        return -1; // This line should never be reached for a valid rotated array
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends