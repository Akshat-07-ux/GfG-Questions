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

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}


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
    // Function to count the number of nodes in loop.
    int countNodesinLoop(Node *head) {
        Node *slow = head;
        Node *fast = head;

        // Step 1: Detect loop using Floyd’s Cycle Detection algorithm
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // Move slow by 1
            fast = fast->next->next;    // Move fast by 2

            if (slow == fast) {
                // Loop detected, now count the loop length
                return countLoopLength(slow);
            }
        }

        // No loop
        return 0;
    }

  private:
    // Helper function to count nodes in loop
    int countLoopLength(Node* loopNode) {
        Node* temp = loopNode;
        int count = 1;

        while (temp->next != loopNode) {
            count++;
            temp = temp->next;
        }

        return count;
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
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        loopHere(head, tail, k);

        Solution ob;
        cout << ob.countNodesinLoop(head) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends