//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
        
};


void displayList(Node *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}



// } Driver Code Ends

// User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }

};
*/

bool isSorted(Node* head) {
    if (!head || !head->next) return true; // 0 or 1 node = sorted by default

    bool nonIncreasing = true, nonDecreasing = true;
    Node* curr = head;

    while (curr->next) {
        if (curr->data < curr->next->data)
            nonIncreasing = false;
        if (curr->data > curr->next->data)
            nonDecreasing = false;
        curr = curr->next;
    }

    return nonIncreasing || nonDecreasing;
}



//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        cout<<isSorted(head) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends