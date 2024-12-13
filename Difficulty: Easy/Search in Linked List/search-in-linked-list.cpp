//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to find the minimum in a rotated sorted array
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

    // Function to find the score of the array based on the marking algorithm
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        set<pair<int, int>> elements; // Store (value, index) pairs
        vector<bool> marked(n, false);

        for (int i = 0; i < n; ++i) {
            elements.insert({nums[i], i});
        }

        for (auto it = elements.begin(); it != elements.end(); ++it) {
            int value = it->first;
            int index = it->second;

            if (!marked[index]) {
                score += value;
                marked[index] = true;
                if (index > 0) marked[index - 1] = true;
                if (index < n - 1) marked[index + 1] = true;
            }
        }

        return score;
    }

    // Function to check if a key is present in the linked list
    bool searchKey(int n, Node* head, int key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n - 1; ++i) {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        int key;
        cin >> key;
        Solution ob;
        cout << ob.searchKey(n, head, key) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends