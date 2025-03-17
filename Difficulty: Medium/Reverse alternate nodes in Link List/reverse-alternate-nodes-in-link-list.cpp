//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* A linked list node */
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void insert(Node*& start, const vector<int>& arr) {
    Node* temp;
    for (int i = 0; i < arr.size(); i++) {
        if (i == 0) {
            start = new Node(arr[i]);
            temp = start;
        } else {
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends

/*
  reverse alternate nodes and append at the end
  The input list will have at least one element
  Node is defined as
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
class Solution {
public:
    void rearrange(Node* head) {
        if (!head || !head->next) return; // If list is empty or has only one node, return.

        Node* odd = head;         // Points to the original linked list
        Node* even = head->next;  // Points to the extracted alternate list
        Node* evenHead = even;    // Stores head of extracted list

        // Step 1: Extract alternate nodes
        while (odd && odd->next) {
            odd->next = even->next;
            odd = odd->next;
            if (odd) {
                even->next = odd->next;
                even = even->next;
            }
        }

        // Step 2: Reverse the extracted list
        Node* prev = NULL;
        Node* curr = evenHead;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        evenHead = prev;  // New head of reversed extracted list

        // Step 3: Append the reversed list to the end of the original list
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = evenHead;
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore(); // Ignore newline after t input

    while (t--) {
        vector<int> arr;
        string input;

        // Read the array of linked list elements
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* start = NULL;
        insert(start, arr);

        Solution ob;
        ob.rearrange(start);
        printList(start);

        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends