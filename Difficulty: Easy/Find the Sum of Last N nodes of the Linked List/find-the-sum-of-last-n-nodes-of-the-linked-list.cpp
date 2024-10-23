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


// } Driver Code Ends
class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
   int sumOfLastN_Nodes(struct Node* head, int n) {
        // Step 1: Initialize two pointers
        Node* fast = head;
        Node* slow = head;
        
        // Step 2: Move the 'fast' pointer 'n' steps ahead
        for (int i = 0; i < n; i++) {
            if (fast != nullptr) {
                fast = fast->next;
            }
        }
        
        // Step 3: Move both 'fast' and 'slow' pointers one step at a time
        // When 'fast' reaches the end, 'slow' will be at the (L-n+1)th node
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Step 4: Sum the last 'n' nodes starting from 'slow'
        int sum = 0;
        while (slow != nullptr) {
            sum += slow->data;
            slow = slow->next;
        }
        
        return sum;
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
        int n;
        cin >> n;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        cout << ob.sumOfLastN_Nodes(head, n) << endl;
    }
    return 0;
}
// } Driver Code Ends