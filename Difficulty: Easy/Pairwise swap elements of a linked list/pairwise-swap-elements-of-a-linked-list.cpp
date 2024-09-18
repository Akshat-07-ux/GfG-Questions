//{ Driver Code Starts


#include <bits/stdc++.h>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
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
    Node* pairWiseSwap(Node* head) {
        // If the list is empty or has only one node, no swapping is needed
        if (head == NULL || head->next == NULL) 
            return head;
        
        // Initialize the previous and current pointers
        Node* prev = head;
        Node* curr = head->next;
        
        // New head will be the second node
        head = curr;
        
        while (true) {
            Node* next = curr->next; // Store the next node of the current pair
            curr->next = prev; // Swap the current pair
            
            // If there's no node left or only one node left after this pair, adjust the last pointer
            if (next == NULL || next->next == NULL) {
                prev->next = next;
                break;
            }
            
            // Connect the previous node with the next pair
            prev->next = next->next;
            
            // Move to the next pair of nodes
            prev = next;
            curr = prev->next;
        }
        
        return head;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t input

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

        if (arr.empty()) {
            cout << -1 << endl; // handle empty input
            continue;
        }

        // Create linked list from the input array
        Node* head = new Node(arr[0]);
        Node* tail = head;
        map<Node*, int> mp;
        mp[head] = head->data;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
            mp[tail] = tail->data;
        }

        Node* failure = new Node(-1);
        Solution ob;
        head = ob.pairWiseSwap(head);
        int flag = 0;
        Node* temp = head;
        while (temp) {
            if (mp[temp] != temp->data) {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag)
            printList(failure);
        else
            printList(head);
    }
    return 0;
}

// } Driver Code Ends