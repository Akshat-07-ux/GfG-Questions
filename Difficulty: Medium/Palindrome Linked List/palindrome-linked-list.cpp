//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    // Function to reverse a linked list
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        
        while (curr != nullptr) {
            next = curr->next; // Store the next node
            curr->next = prev; // Reverse the current node's pointer
            prev = curr;       // Move prev to current node
            curr = next;       // Move current to next node
        }
        
        return prev; // New head of the reversed list
    }
    
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        if (head == nullptr || head->next == nullptr) {
            return true; // Empty list or single node list is a palindrome
        }
        
        // Step 1: Find the middle of the linked list
        Node *slow = head, *fast = head;
        
        // Move slow by 1 and fast by 2, so when fast reaches the end, slow will be at the middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the linked list
        slow = reverseList(slow); // slow is now at the start of the second half
        Node* secondHalfHead = slow; // To restore the list later
        
        // Step 3: Compare the first half and the reversed second half
        Node* firstHalfHead = head;
        while (slow != nullptr) {
            if (firstHalfHead->data != slow->data) {
                return false; // Not a palindrome
            }
            firstHalfHead = firstHalfHead->next;
            slow = slow->next;
        }
        
        // Step 4: (Optional) Restore the second half of the linked list
        reverseList(secondHalfHead);
        
        return true; // The list is a palindrome
    }
};


//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}

// } Driver Code Ends