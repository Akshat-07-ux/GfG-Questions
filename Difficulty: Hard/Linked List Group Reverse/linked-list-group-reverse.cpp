//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
public:
    // Helper function to get length of linked list
    int getLength(Node* head) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    
    // Helper function to reverse a portion of linked list
    Node* reverseGroup(Node* start, int k) {
        if (!start) return NULL;
        
        Node *curr = start;
        Node *prev = NULL;
        Node *next = NULL;
        int count = 0;
        
        // Reverse k nodes
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        // Connect with rest of the list
        if (next != NULL) {
            start->next = reverseKGroup(next, k);
        }
        
        return prev;
    }
    
    Node *reverseKGroup(Node *head, int k) {
        // If list is empty or k is 1, no need to reverse
        if (head == NULL || k == 1) return head;
        
        int length = getLength(head);
        
        // If k is greater than length, reverse the whole list
        if (k > length) {
            return reverseGroup(head, length);
        }
        
        // Main reversal logic
        return reverseGroup(head, k);
    }
};

//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

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
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends