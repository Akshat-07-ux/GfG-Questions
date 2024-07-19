//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        num1 = reverseList(num1);
        num2 = reverseList(num2);
        
        Node* dummy = new Node(0);
        Node* curr = dummy;
        int carry = 0;
        
        while (num1 || num2 || carry) {
            int sum = carry;
            if (num1) {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2) {
                sum += num2->data;
                num2 = num2->next;
            }
            
            curr->next = new Node(sum % 10);
            carry = sum / 10;
            curr = curr->next;
        }
        
        Node* result = reverseList(dummy->next);
        delete dummy;
        
        // Remove leading zeros
        while (result && result->data == 0 && result->next) {
            Node* temp = result;
            result = result->next;
            delete temp;
        }
        
        return result;
    }

private:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends