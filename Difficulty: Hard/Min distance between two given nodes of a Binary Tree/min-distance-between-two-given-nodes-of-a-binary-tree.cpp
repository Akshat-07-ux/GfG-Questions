//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
public:
    // Function to find the Lowest Common Ancestor of nodes a and b.
    Node* findLCA(Node* root, int a, int b) {
        if (root == NULL) return NULL;
        
        // If either a or b matches with root, report root as LCA
        if (root->data == a || root->data == b) return root;
        
        // Look for keys in left and right subtrees
        Node* left_lca = findLCA(root->left, a, b);
        Node* right_lca = findLCA(root->right, a, b);
        
        // If a and b are found in left and right subtrees, root is the LCA
        if (left_lca && right_lca) return root;
        
        // Otherwise, return the non-null subtree (if any)
        return (left_lca != NULL) ? left_lca : right_lca;
    }
    
    // Function to find the distance from the root to a target node.
    int findDistance(Node* root, int target, int dist) {
        if (root == NULL) return -1;
        
        // If the target is found, return the current distance.
        if (root->data == target) return dist;
        
        // Recur for left and right subtrees and find the distance.
        int left = findDistance(root->left, target, dist + 1);
        if (left != -1) return left;
        
        return findDistance(root->right, target, dist + 1);
    }
    
    // Function to return the minimum distance between nodes a and b.
    int findDist(Node* root, int a, int b) {
        // Step 1: Find the LCA of the two nodes.
        Node* lca = findLCA(root, a, b);
        
        // Step 2: Find the distance from LCA to a and LCA to b.
        int d1 = findDistance(lca, a, 0);
        int d2 = findDistance(lca, b, 0);
        
        // Step 3: The total distance is the sum of the two distances.
        return d1 + d2;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends