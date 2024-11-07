//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x)
        : data(x)
        , next(nullptr) {}
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        head = head->next;
    }
    cout << '\n';
}


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

    bool isSmaller(Node* head1, Node* head2) {
        // Calculate lengths of both linked lists
        int len1 = 0, len2 = 0;
        Node* temp1 = head1;
        Node* temp2 = head2;

        while (temp1 != nullptr) {
            len1++;
            temp1 = temp1->next;
        }

        while (temp2 != nullptr) {
            len2++;
            temp2 = temp2->next;
        }

        // Compare lengths
        if (len1 < len2) return true;
        if (len1 > len2) return false;

        // If lengths are equal, compare node by node
        temp1 = head1;
        temp2 = head2;
        while (temp1 && temp2) {
            if (temp1->data < temp2->data) return true;
            if (temp1->data > temp2->data) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return false;  // they are equal
    }

    Node* subLinkedList(Node* head1, Node* head2) {
        // Check which number is larger and set head1 to the larger number
        if (isSmaller(head1, head2)) swap(head1, head2);

        // Reverse both lists
        head1 = reverse(head1);
        head2 = reverse(head2);

        Node* result = nullptr;
        Node* tail = nullptr;
        int carry = 0;

        // Perform the subtraction
        while (head1 != nullptr || head2 != nullptr) {
            int x = (head1 != nullptr) ? head1->data : 0;
            int y = (head2 != nullptr) ? head2->data : 0;

            int diff = x - y - carry;
            if (diff < 0) {
                diff += 10;
                carry = 1;
            } else {
                carry = 0;
            }

            Node* newNode = new Node(diff);
            if (result == nullptr) {
                result = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            if (head1) head1 = head1->next;
            if (head2) head2 = head2->next;
        }

        // Reverse the result to get the correct order
        result = reverse(result);

        // Remove leading zeros
        while (result != nullptr && result->data == 0) {
            Node* temp = result;
            result = result->next;
            delete temp;
        }

        // If the result is empty (only zeros), return a single node with value 0
        return result ? result : new Node(0);
    }
};

//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        cin >> input1 >> input2;
        for (char ch : input1) {
            int tmp = ch - '0';
            Node* new_node = new Node(tmp);
            if (!head1) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        for (char ch : input2) {
            int tmp = ch - '0';
            Node* new_node = new Node(tmp);
            if (!head2) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node* result = obj.subLinkedList(head1, head2);
        printList(result);
    }
    return 0;
}

// } Driver Code Ends