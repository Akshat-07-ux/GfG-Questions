//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
    public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        if (head == NULL || head->next == head)
            return head;
            
        Node *prev = NULL;
        Node *current = head;
        Node *next;
        
        // Store the head to connect last node to it later
        Node *firstNode = head;
        
        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);
        
        // Connect last node (original head) to new head (prev)
        firstNode->next = prev;
        
        return prev;
    }
    
    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        if (head == NULL)
            return NULL;
            
        // If only one node
        if (head->next == head && head->data == key)
            return NULL;
            
        Node *curr = head, *prev = NULL;
        
        // Find the node to delete
        while (curr->next != head && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }
        
        // If key is not found
        if (curr->next == head && curr->data != key)
            return head;
            
        // If key is found
        // Case 1: If node to be deleted is head
        if (curr == head) {
            prev = head;
            while (prev->next != head)
                prev = prev->next;
                
            head = curr->next;
            prev->next = head;
            delete curr;
        }
        // Case 2: If node to be deleted is not head
        else {
            prev->next = curr->next;
            delete curr;
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

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends