//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    std::vector<int> kthLargest(int k, int arr[], int n) {
        std::vector<int> result;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Min-heap to store the k largest elements
        
        for (int i = 0; i < n; i++) {
            // Insert the current element into the heap
            if (minHeap.size() < k) {
                minHeap.push(arr[i]);
            } else if (arr[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(arr[i]);
            }
            
            // If the heap has fewer than k elements, the k-th largest doesn't exist
            if (minHeap.size() < k) {
                result.push_back(-1);
            } else {
                result.push_back(minHeap.top());
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends