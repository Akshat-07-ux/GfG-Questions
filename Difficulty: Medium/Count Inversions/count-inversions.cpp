//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    // Helper function to merge two subarrays and count inversions.
    int mergeAndCount(vector<int> &arr, vector<int> &temp, int left, int mid, int right) {
        int i = left;    // Starting index for left subarray
        int j = mid + 1; // Starting index for right subarray
        int k = left;    // Starting index for temporary array
        int inv_count = 0;

        // Merge the two subarrays
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                // All elements left in the left subarray are greater than arr[j]
                inv_count += (mid - i + 1);
            }
        }

        // Copy the remaining elements of the left subarray, if any
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy the remaining elements of the right subarray, if any
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy the sorted subarray back into the original array
        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }

        return inv_count;
    }

    // Function to use merge sort and count inversions
    int mergeSortAndCount(vector<int> &arr, vector<int> &temp, int left, int right) {
        int mid, inv_count = 0;
        if (left < right) {
            mid = (left + right) / 2;

            // Count inversions in the left subarray
            inv_count += mergeSortAndCount(arr, temp, left, mid);

            // Count inversions in the right subarray
            inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

            // Count inversions while merging
            inv_count += mergeAndCount(arr, temp, left, mid, right);
        }
        return inv_count;
    }

    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        vector<int> temp(arr.size());
        return mergeSortAndCount(arr, temp, 0, arr.size() - 1);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends