//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x)
        : data(x)
        , next(NULL) {}
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void addressstore(vector<Node*>& arr, Node* head) {
    Node* temp = head;
    int i = 0;
    while (temp) {
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(const vector<Node*>& before, const vector<Node*>& after, int num, int k) {
    if (k > num)
        return true;

    for (int i = 0; i < num; i++) {
        if ((i == k - 1) || (i == num - k)) {
            if (!((before[k - 1] == after[num - k]) &&
                  (before[num - k] == after[k - 1]))) {
                return false;
            }
        } else {
            if (before[i] != after[i]) {
                return false;
            }
        }
    }
    return true;
}


// } Driver Code Ends
// User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
}
*/

// Function to swap Kth node from beginning and end in a linked list.
class Solution {
 public:
    Node* swapKthNode(Node* head, int k) {
        // Edge case: empty list or single node
        if (!head || !head->next) return head;

        // Step 1: Calculate the length of the linked list
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // If k is greater than the number of nodes, return the head as is
        if (k > n) return head;

        // If k is the same from both ends, no need to swap
        if (2 * k - 1 == n) return head;

        // Step 2: Find the kth node from the beginning and the end
        Node* firstPrev = NULL; // To keep track of the previous node of kth node from start
        Node* first = head;
        for (int i = 1; i < k; i++) {
            firstPrev = first;
            first = first->next;
        }

        Node* secondPrev = NULL; // To keep track of the previous node of kth node from end
        Node* second = head;
        for (int i = 1; i < n - k + 1; i++) {
            secondPrev = second;
            second = second->next;
        }

        // Step 3: Swap the nodes by adjusting the links
        if (firstPrev) firstPrev->next = second;
        if (secondPrev) secondPrev->next = first;

        // Swap the next pointers of the kth nodes
        Node* tempNode = first->next;
        first->next = second->next;
        second->next = tempNode;

        // Step 4: Update the head if necessary
        if (k == 1) head = second; // If the first node was swapped
        if (k == n) head = first;  // If the last node was swapped

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

        int k;
        cin >> k;
        cin.ignore();

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }

        int num = arr.size();
        vector<Node*> before(num);
        addressstore(before, head);

        Solution ob;
        head = ob.swapKthNode(head, k);

        vector<Node*> after(num);
        addressstore(after, head);

        if (check(before, after, num, k))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}
// } Driver Code Ends