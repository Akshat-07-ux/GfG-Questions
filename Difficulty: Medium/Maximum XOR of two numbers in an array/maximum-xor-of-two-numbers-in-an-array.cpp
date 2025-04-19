//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class TrieNode {
public:
    TrieNode* children[2];
    
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Solution {
private:
    TrieNode* root;

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 20; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    int findMaxXor(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 20; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int toggledBit = 1 - bit;
            if (node->children[toggledBit]) {
                maxXor |= (1 << i);
                node = node->children[toggledBit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXor;
    }

public:
    int maxXor(vector<int> &arr) {
        root = new TrieNode();
        int maxXorResult = 0;

        insert(arr[0]);  // insert first number

        for (int i = 1; i < arr.size(); ++i) {
            maxXorResult = max(maxXorResult, findMaxXor(arr[i]));
            insert(arr[i]);
        }

        return maxXorResult;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends