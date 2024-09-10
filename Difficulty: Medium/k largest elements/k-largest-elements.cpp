//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    vector<int> kLargest(int arr[], int n, int k) {
        // Min-heap to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // Iterate through the array
        for (int i = 0; i < n; ++i) {
            if (minHeap.size() < k) {
                // If heap size is less than k, push the current element
                minHeap.push(arr[i]);
            } else if (arr[i] > minHeap.top()) {
                // If current element is larger than the smallest in the heap
                minHeap.pop();  // Remove the smallest element
                minHeap.push(arr[i]);  // Add the new element
            }
        }
        
        // Extract elements from heap and store them in a vector
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        
        // Reverse the vector to get the elements in decreasing order
        reverse(result.begin(), result.end());
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends