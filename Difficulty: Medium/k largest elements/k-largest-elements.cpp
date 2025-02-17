//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int> maxHeap(arr.begin(), arr.end());  // Max heap

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(maxHeap.top());  // Get largest element
            maxHeap.pop();  // Remove it from heap
        }
        return result;  // Already in decreasing order
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.kLargest(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends