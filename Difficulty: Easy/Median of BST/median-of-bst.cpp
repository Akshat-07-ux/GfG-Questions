//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
// Helper function to count the total number of nodes in the BST
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Helper function to find the kth node during an inorder traversal
void findKthNode(Node* root, int& count, int k, int& result) {
    if (!root) return;

    // Inorder traversal: visit left subtree
    findKthNode(root->left, count, k, result);
    
    count++;
    // If the current node is the kth node, store its value in result
    if (count == k) {
        result = root->data;
        return;
    }

    // Inorder traversal: visit right subtree
    findKthNode(root->right, count, k, result);
}

// Main function to find the median of the BST
float findMedian(Node* root) {
    if (!root) return 0;

    // Step 1: Get the total number of nodes
    int n = countNodes(root);
    
    // Step 2: Find the median
    int count = 0;
    int mid1 = 0, mid2 = 0;

    // If number of nodes is odd, find the middle node
    if (n % 2 == 1) {
        findKthNode(root, count, (n + 1) / 2, mid1);
        return mid1;
    }
    // If number of nodes is even, find the average of the two middle nodes
    else {
        findKthNode(root, count, n / 2, mid1);         // N/2 th node
        count = 0;  // Reset count for next traversal
        findKthNode(root, count, (n / 2) + 1, mid2);   // (N/2 + 1) th node
        return (mid1 + mid2) / 2.0;
    }
}

