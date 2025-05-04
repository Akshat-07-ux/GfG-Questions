//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends

/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
public:
    // Function to rearrange the linked list based on vowels
    struct Node* arrangeCV(Node* head) {
        if (!head || !head->next) return head;

        // Dummy heads and tails for two separate lists
        Node* vowelHead = nullptr, *vowelTail = nullptr;
        Node* consHead = nullptr, *consTail = nullptr;

        Node* curr = head;

        while (curr) {
            char ch = curr->data;
            Node* next = curr->next;
            curr->next = nullptr; // Disconnect current node

            if (isVowel(ch)) {
                if (!vowelHead) {
                    vowelHead = vowelTail = curr;
                } else {
                    vowelTail->next = curr;
                    vowelTail = vowelTail->next;
                }
            } else {
                if (!consHead) {
                    consHead = consTail = curr;
                } else {
                    consTail->next = curr;
                    consTail = consTail->next;
                }
            }

            curr = next;
        }

        // Combine vowel list with consonant list
        if (vowelTail) {
            vowelTail->next = consHead;
            return vowelHead;
        } else {
            return consHead;
        }
    }

  private:
    // Utility function to check if a character is a vowel
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};



//{ Driver Code Starts.

// task is to complete this function
int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<char> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        char number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            return NULL;
        }
        char val = arr[0];
        int size = arr.size();

        Node *head = new Node(val);
        Node *tail = head;

        for (int i = 1; i < size; i++) {
            val = arr[i];
            tail->next = new Node(val);
            tail = tail->next;
        }

        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends