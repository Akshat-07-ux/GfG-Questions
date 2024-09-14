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
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
 public:
    Node* findIntersection(Node* head1, Node* head2) {
        Node* dummy = new Node(0); // Dummy node to help with the construction of the new list
        Node* tail = dummy;        // Tail to keep track of the last node in the new list

        // Traverse both lists until one of them becomes null
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->data == head2->data) {
                // If data matches, add it to the new list
                tail->next = new Node(head1->data);
                tail = tail->next;
                head1 = head1->next;
                head2 = head2->next;
            } else if (head1->data < head2->data) {
                // Move ahead in list1 if its data is smaller
                head1 = head1->next;
            } else {
                // Move ahead in list2 if its data is smaller
                head2 = head2->next;
            }
        }

        // Return the next of the dummy node as the new list's head
        return dummy->next;
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

        getline(cin, input1); // Read the entire line for LL1 elements
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

        getline(cin, input2); // Read the entire line for LL2 elements
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
        Node *result = obj.findIntersection(head1, head2);

        printList(result);
        // cout << endl;
    }
    return 0;
}

// } Driver Code Ends