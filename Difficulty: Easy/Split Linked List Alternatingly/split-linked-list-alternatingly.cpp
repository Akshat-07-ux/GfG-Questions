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
/*
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

class Solution {
public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        if (head == NULL) return {NULL, NULL};  // If the list is empty, return two empty lists

        // Initialize two dummy nodes for the two sublists
        Node* aHead = NULL;  // Points to the head of the first list
        Node* bHead = NULL;  // Points to the head of the second list
        Node* aTail = NULL;  // Points to the last node of the first list
        Node* bTail = NULL;  // Points to the last node of the second list

        Node* current = head;  // Pointer to traverse the original list
        bool toggle = true;  // Boolean to toggle between lists

        while (current != NULL) {
            if (toggle) {
                // Add current node to list 'a'
                if (aHead == NULL) {
                    aHead = current;
                    aTail = current;
                } else {
                    aTail->next = current;
                    aTail = aTail->next;
                }
            } else {
                // Add current node to list 'b'
                if (bHead == NULL) {
                    bHead = current;
                    bTail = current;
                } else {
                    bTail->next = current;
                    bTail = bTail->next;
                }
            }
            toggle = !toggle;  // Switch lists for next node
            current = current->next;
        }

        // Terminate both lists
        if (aTail != NULL) aTail->next = NULL;
        if (bTail != NULL) bTail->next = NULL;

        // Return the two lists
        return {aHead, bHead};
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
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

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends