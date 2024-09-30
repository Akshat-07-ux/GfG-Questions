//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
public:
    // Function to count the total number of nodes in the tree.
    int countNodes(Node* root) {
        if (root == NULL)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Function to check if the tree is complete or not.
    bool isComplete(Node* root, int index, int totalNodes) {
        // An empty tree is complete.
        if (root == NULL)
            return true;
        
        // If the index of the current node is greater than or equal to the total number of nodes,
        // it means the tree is not complete.
        if (index >= totalNodes)
            return false;
        
        // Recursively check the left and right subtrees.
        return isComplete(root->left, 2 * index + 1, totalNodes) &&
               isComplete(root->right, 2 * index + 2, totalNodes);
    }

    // Function to check if the tree follows the max-heap property.
    bool isMaxHeap(Node* root) {
        // If the node is a leaf node, it is a max-heap by default.
        if (root->left == NULL && root->right == NULL)
            return true;
        
        // If there is only a left child, check if the root is greater than the left child.
        if (root->right == NULL)
            return root->data >= root->left->data;
        
        // If there are both left and right children, check if the root is greater than both children.
        if (root->data >= root->left->data && root->data >= root->right->data)
            // Recursively check the max-heap property for the left and right subtrees.
            return isMaxHeap(root->left) && isMaxHeap(root->right);
        
        return false;
    }

    // Main function to check if the binary tree is a max-heap.
    bool isHeap(Node* root) {
        if (root == NULL)
            return true;
        
        int totalNodes = countNodes(root);
        int index = 0;
        
        // Check if the tree is complete and satisfies the max-heap property.
        return isComplete(root, index, totalNodes) && isMaxHeap(root);
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends