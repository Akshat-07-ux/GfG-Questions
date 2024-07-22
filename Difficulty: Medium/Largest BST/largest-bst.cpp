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
/* Tree node structure  used in the program

struct Node {
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
    struct Info {
        bool isBST;
        int size;
        int min;
        int max;
    };

    Info largestBstUtil(Node* root, int& maxSize) {
        // Base case: An empty tree is a BST of size 0
        if (root == nullptr) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        // Recursively get info from left and right subtrees
        Info leftInfo = largestBstUtil(root->left, maxSize);
        Info rightInfo = largestBstUtil(root->right, maxSize);

        Info curr;
        curr.size = leftInfo.size + rightInfo.size + 1;

        // Current node is a BST if:
        // 1. Left subtree is a BST
        // 2. Right subtree is a BST
        // 3. Maximum value in the left subtree is less than the current node's value
        // 4. Minimum value in the right subtree is greater than the current node's value
        if (leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && root->data < rightInfo.min) {
            curr.isBST = true;
            curr.min = std::min(leftInfo.min, root->data);
            curr.max = std::max(rightInfo.max, root->data);

            // Update maximum size of BST found so far
            maxSize = std::max(maxSize, curr.size);
        } else {
            curr.isBST = false;
        }

        return curr;
    }

    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node* root) {
        int maxSize = 0;
        largestBstUtil(root, maxSize);
        return maxSize;
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
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends