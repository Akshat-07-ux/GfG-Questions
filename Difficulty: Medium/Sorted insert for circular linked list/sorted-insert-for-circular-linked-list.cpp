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

void printList(Node *head) {
    if (head == NULL)
        return;

    Node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << "\n";
}


// } Driver Code Ends
/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }

};
 */

// This function should return head of
// the modified list
class Solution {
public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);

        // If the list is empty, create a new node that points to itself
        if (head == NULL) {
            newNode->next = newNode;
            return newNode;
        }

        Node* curr = head;

        // Case 1: Insert before the head (when the data is smaller than head's data)
        if (data <= head->data) {
            // To insert before head, we need to find the last node
            while (curr->next != head) {
                curr = curr->next;
            }
            // Insert the new node before the head
            newNode->next = head;
            curr->next = newNode;
            // If the new data is less than the head, the new node becomes the new head
            return newNode;
        }

        // Case 2: Traverse the list to find the correct position
        curr = head;
        while (curr->next != head && curr->next->data < data) {
            curr = curr->next;
        }

        // Insert the new node in its correct position
        newNode->next = curr->next;
        curr->next = newNode;

        // Return the original head since it is still the smallest
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
        while (ss >> number) {
            arr.push_back(number);
        }
        int x;
        cin >> x;
        cin.ignore();
        Node *head = new Node(arr[0]);
        Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make it circular
        Solution ob;
        Node *ans = ob.sortedInsert(head, x);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends