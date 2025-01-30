//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int minValue(string s, int k) {
        unordered_map<char, int> freq;
        priority_queue<int> maxHeap;

        // Step 1: Count frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        // Step 2: Push all frequencies into a max heap
        for (auto it : freq) {
            maxHeap.push(it.second);
        }

        // Step 3: Remove 'k' characters greedily from the most frequent ones
        while (k > 0 && !maxHeap.empty()) {
            int top = maxHeap.top();
            maxHeap.pop();
            top--; // Decrease frequency
            k--;
            if (top > 0) {
                maxHeap.push(top);
            }
        }

        // Step 4: Compute the final sum of squares
        int result = 0;
        while (!maxHeap.empty()) {
            int count = maxHeap.top();
            maxHeap.pop();
            result += count * count;
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;

        Solution ob;
        cout << ob.minValue(s, k) << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends