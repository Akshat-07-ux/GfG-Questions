//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/*
// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
public:
    // Function to sort a k-sorted doubly linked list
    DLLNode* sortAKSortedDLL(DLLNode *head, int k) {
        if (head == NULL || head->next == NULL) return head;
        
        // Min heap to store the nodes
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // Create a new head pointer for the sorted list
        DLLNode *newHead = NULL, *last = NULL;

        DLLNode *curr = head;

        // Add first k+1 elements to the heap
        for (int i = 0; curr != NULL && i <= k; i++) {
            minHeap.push(curr->data);
            curr = curr->next;
        }

        // Process the rest of the nodes
        while (!minHeap.empty()) {
            // Extract the minimum element from the heap
            int minVal = minHeap.top();
            minHeap.pop();

            // Create the new node for the sorted DLL
            if (newHead == NULL) {
                newHead = new DLLNode(minVal);
                last = newHead;
            } else {
                last->next = new DLLNode(minVal);
                last->next->prev = last;
                last = last->next;
            }

            // If there are more elements to process, add them to the heap
            if (curr != NULL) {
                minHeap.push(curr->data);
                curr = curr->next;
            }
        }

        return newHead;
    }
};

//{ Driver Code Starts.

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data) {
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end,
    // next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver
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

        int k;
        cin >> k;
        cin.ignore();

        DLLNode *head = new DLLNode(arr[0]);
        DLLNode *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            push(&tail, arr[i]);
        }
        Solution obj;
        printList(obj.sortAKSortedDLL(head, k));
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends