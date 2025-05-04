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

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*Link list node
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

class Solution {
   public:
    Node* insertionSort(struct Node* head_ref) {
        if (!head_ref || !head_ref->next) return head_ref;

        Node* sorted = nullptr; // Start with an empty sorted list

        Node* current = head_ref;
        while (current != nullptr) {
            Node* next = current->next; // Save the next node
            sorted = sortedInsert(sorted, current); // Insert current into sorted list
            current = next; // Move to the next node
        }

        return sorted;
    }

  private:
    // Helper function to insert a node into the sorted list
    Node* sortedInsert(Node* head, Node* newNode) {
        if (!head || newNode->data <= head->data) {
            newNode->next = head;
            return newNode;
        }

        Node* current = head;
        while (current->next && current->next->data < newNode->data) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.insertionSort(head);
        printList(ans);
        cout << '~' << endl;
    }
    return 0;
}
// } Driver Code Ends