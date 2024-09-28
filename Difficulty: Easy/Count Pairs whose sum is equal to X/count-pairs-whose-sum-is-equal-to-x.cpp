//{ Driver Code Starts
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

// Function to print the linked list
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
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
    // Function to count pairs whose sum equals x
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Hash set to store elements of the first linked list
        std::unordered_set<int> set;

        // Traverse the first linked list and store its elements in the set
        Node* current1 = head1;
        while (current1 != NULL) {
            set.insert(current1->data);
            current1 = current1->next;
        }

        // Traverse the second linked list and check if (x - current element) exists in the set
        int count = 0;
        Node* current2 = head2;
        while (current2 != NULL) {
            if (set.find(x - current2->data) != set.end()) {
                count++;
            }
            current2 = current2->next;
        }

        return count;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head1 == nullptr) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head2 == nullptr) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        int x;
        cin >> x;
        cin.ignore();
        Solution obj;
        int result = obj.countPairs(head1, head2, x);
        cout << result << '\n'; // Print the number of pairs found
    }
    return 0;
}

// } Driver Code Ends