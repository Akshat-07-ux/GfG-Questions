//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node* root) {
    Node* temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    // Helper function to reverse the linked list
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* nextNode = nullptr;
        
        while (curr != nullptr) {
            nextNode = curr->next;  // Store the next node
            curr->next = prev;      // Reverse the current node's pointer
            prev = curr;            // Move prev and curr one step forward
            curr = nextNode;
        }
        return prev;
    }
    
    Node *compute(Node *head) {
        // Step 1: Reverse the linked list
        head = reverseList(head);
        
        // Step 2: Traverse the reversed list and remove nodes
        Node* curr = head;
        Node* maxNode = head;
        
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->data < maxNode->data) {
                // Remove the node if the next node's data is less than maxNode's data
                curr->next = curr->next->next;
            } else {
                // Update maxNode and move the current pointer
                curr = curr->next;
                maxNode = curr;
            }
        }
        
        // Step 3: Reverse the list back to its original order
        head = reverseList(head);
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }
        Solution ob;
        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Node* result = ob.compute(head);
        print(result);
        cout << endl;
    }
}

// } Driver Code Ends