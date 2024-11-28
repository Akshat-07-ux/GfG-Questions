//{ Driver Code Starts
// Initial Template for C++
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

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // Base case: If the list is empty or has only one node.
        if (!head || !head->next) {
            return head;
        }

        // Step 1: Split the linked list into two halves.
        Node* mid = getMiddle(head);
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;

        // Step 2: Recursively sort both halves.
        left = mergeSort(left);
        right = mergeSort(right);

        // Step 3: Merge the sorted halves.
        return merge(left, right);
    }

private:
    // Helper function to find the middle of the linked list.
    Node* getMiddle(Node* head) {
        if (!head) return head;

        Node* slow = head;
        Node* fast = head->next;

        // Move `fast` two steps and `slow` one step to find the middle.
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Helper function to merge two sorted linked lists.
    Node* merge(Node* left, Node* right) {
        // Dummy node to simplify the merge process.
        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (left && right) {
            if (left->data <= right->data) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        // Attach the remaining elements.
        if (left) tail->next = left;
        if (right) tail->next = right;

        Node* sortedHead = dummy->next;
        delete dummy;  // Free the dummy node.
        return sortedHead;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends