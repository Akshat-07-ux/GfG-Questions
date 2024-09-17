//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
class Solution {
   public:
    Node* deleteMid(Node* head) {
        // If the linked list is empty or has only one node, return NULL
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        
        // Initialize two pointers: slow (moves 1 step) and fast (moves 2 steps)
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL; // To keep track of the node before the slow pointer

        // Move fast pointer 2 steps and slow pointer 1 step until fast reaches the end
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        // Now slow is pointing to the middle node, and prev is the node before slow
        prev->next = slow->next; // Delete the middle node by adjusting the next pointer

        // Return the head of the modified list
        return head;
    }
};

//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

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
        while (ss >> number) {
            arr.push_back(number);
        }
        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution obj;
        head = obj.deleteMid(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends