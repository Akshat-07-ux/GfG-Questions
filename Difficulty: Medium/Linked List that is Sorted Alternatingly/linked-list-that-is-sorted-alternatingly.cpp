//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data =x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to split the alternating sorted list into two lists
    void splitList(Node* head, Node*& ascending, Node*& descending) {
        if (!head) return;

        // `ascending` will point to the first node
        ascending = head;
        head = head->next;

        if (!head) return;

        // `descending` will point to the second node
        descending = head;
        head = head->next;

        Node* ascTail = ascending;
        Node* descTail = descending;

        // Traverse and distribute nodes alternately
        while (head) {
            ascTail->next = head;
            ascTail = ascTail->next;
            head = head->next;

            if (head) {
                descTail->next = head;
                descTail = descTail->next;
                head = head->next;
            }
        }
        ascTail->next = NULL;
        descTail->next = NULL;
    }

    // Function to reverse a linked list
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    // Function to merge two sorted linked lists
    Node* mergeLists(Node* l1, Node* l2) {
        Node dummy(0);
        Node* tail = &dummy;

        while (l1 && l2) {
            if (l1->data < l2->data) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1) tail->next = l1;
        if (l2) tail->next = l2;

        return dummy.next;
    }

    Node* sort(Node* head) {
        if (!head || !head->next) return head;

        Node *ascending = NULL, *descending = NULL;

        // Step 1: Split the list into two lists
        splitList(head, ascending, descending);

        // Step 2: Reverse the descending list to make it sorted
        descending = reverseList(descending);

        // Step 3: Merge the two sorted lists
        return mergeLists(ascending, descending);
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }
        }

        Solution ob;
        Node* newHead = ob.sort(head);
        printList(newHead);
        freeList(newHead);

        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends