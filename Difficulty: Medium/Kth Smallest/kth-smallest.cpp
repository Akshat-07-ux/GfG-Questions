//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    // Partition function similar to the one used in QuickSort
    int partition(std::vector<int> &arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    // Quickselect function to find the kth smallest element
    int quickSelect(std::vector<int> &arr, int low, int high, int k) {
        if (low <= high) {
            int pivotIndex = partition(arr, low, high);

            // If pivot is the kth smallest element
            if (pivotIndex == k - 1) {
                return arr[pivotIndex];
            }
            // If kth smallest element is in the left subarray
            else if (pivotIndex > k - 1) {
                return quickSelect(arr, low, pivotIndex - 1, k);
            }
            // If kth smallest element is in the right subarray
            else {
                return quickSelect(arr, pivotIndex + 1, high, k);
            }
        }
        return -1; // This line will never be reached due to the problem constraints
    }

    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(std::vector<int> &arr, int k) {
        int n = arr.size();
        return quickSelect(arr, 0, n - 1, k);
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl;
    }
    return 0;
}

// } Driver Code Ends