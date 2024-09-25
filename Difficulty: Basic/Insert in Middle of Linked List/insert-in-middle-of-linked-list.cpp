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
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to insert a node in the middle of the linked list.
class Solution {
public:
    Node* insertInMiddle(Node* head, int x) {
        // If the list is empty, create a new node and return it
        if (head == NULL) {
            return new Node(x);
        }
        
        // If there's only one node, insert after it
        if (head->next == NULL) {
            head->next = new Node(x);
            return head;
        }
        
        // Use slow and fast pointers to find the middle
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        // Create a new node with the given value
        Node* newNode = new Node(x);
        
        // Insert the new node after the middle (slow pointer)
        if (fast == NULL) {
            // Even number of nodes
            newNode->next = slow;
            prev->next = newNode;
        } else {
            // Odd number of nodes
            newNode->next = slow->next;
            slow->next = newNode;
        }
        
        return head;
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

        int x;
        cin >> x;
        cin.ignore();

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

        Solution ob;
        Node *ans = ob.insertInMiddle(head, x);
        printList(ans);
    }

    return 0;
}
// } Driver Code Ends