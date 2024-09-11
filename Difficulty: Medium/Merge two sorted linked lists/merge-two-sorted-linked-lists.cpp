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

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}


// } Driver Code Ends


/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Function to merge two sorted linked list.
class Solution {
public:
    // Function to merge two sorted linked lists.
    Node* sortedMerge(Node* head1, Node* head2) {
        // If one of the lists is empty, return the other list.
        if (!head1) return head2;
        if (!head2) return head1;
        
        // Initialize a dummy node to help in merging lists.
        Node* dummy = new Node(0); // A dummy node to hold the merged list
        Node* tail = dummy;        // Pointer to build the merged list
        
        // Traverse both lists until one of them becomes empty.
        while (head1 && head2) {
            if (head1->data <= head2->data) {
                // If the data in the first list's node is smaller or equal, append it to the result.
                tail->next = head1;
                head1 = head1->next;
            } else {
                // Otherwise, append the node from the second list to the result.
                tail->next = head2;
                head2 = head2->next;
            }
            // Move the tail pointer forward.
            tail = tail->next;
        }
        
        // Append the remaining nodes from whichever list is non-empty.
        if (head1) {
            tail->next = head1;
        } else {
            tail->next = head2;
        }
        
        // The merged list is pointed by dummy->next.
        Node* mergedHead = dummy->next;
        delete dummy; // Free the memory allocated for the dummy node
        return mergedHead;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head1 == nullptr) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head2 == nullptr) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends