//{ Driver Code Starts
#include <stdint.h>

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *npx;

    Node(int x) {
        data = x;
        npx = NULL;
    }
};

struct Node *XOR(struct Node *a, struct Node *b) {
    return (struct Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

struct Node *insert(struct Node *head, int data);

vector<int> getList(struct Node *head);

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        struct Node *head = NULL;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            head = insert(head, number);
        }

        vector<int> vec = getList(head);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
        for (int i = vec.size() - 1; i >= 0; i--) {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }
    return (0);
}

// } Driver Code Ends


/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/

// Function to insert data at the front of the list
struct Node *insert(struct Node *head, int data) {
    // Create a new node
    Node *newNode = new Node(data);
    
    // XOR of new node's npx will be current head (since previous is NULL)
    newNode->npx = XOR(NULL, head);

    // If the list is not empty, update the npx of the current head
    if (head != NULL) {
        Node* next = XOR(NULL, head->npx); // Get the next node
        head->npx = XOR(newNode, next);    // Update head's npx to XOR with new node
    }

    // New node becomes the new head
    return newNode;
}

// Function to return the list as a vector in forward direction
vector<int> getList(struct Node *head) {
    vector<int> result;
    Node *curr = head;
    Node *prev = NULL;
    Node *next;

    // Traverse the list
    while (curr != NULL) {
        // Add current node's data to result
        result.push_back(curr->data);

        // Get the next node using XOR
        next = XOR(prev, curr->npx);

        // Update prev and curr for the next iteration
        prev = curr;
        curr = next;
    }

    return result;
}
