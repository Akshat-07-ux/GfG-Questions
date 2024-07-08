//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], int n) {
        return mergeSort(arr, 0, n - 1);
    }

private:
    long long mergeSort(long long arr[], int left, int right) {
        long long inv_count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            inv_count += mergeSort(arr, left, mid);
            inv_count += mergeSort(arr, mid + 1, right);
            inv_count += merge(arr, left, mid, right);
        }
        return inv_count;
    }
    
    long long merge(long long arr[], int left, int mid, int right) {
        int i = left, j = mid + 1, k = 0;
        long long inv_count = 0;
        long long temp[right - left + 1];
        
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inv_count += mid - i + 1;
            }
        }
        
        while (i <= mid)
            temp[k++] = arr[i++];
        
        while (j <= right)
            temp[k++] = arr[j++];
        
        for (i = left, k = 0; i <= right; i++, k++)
            arr[i] = temp[k];
        
        return inv_count;
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends