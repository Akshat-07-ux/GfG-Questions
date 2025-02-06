//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
 public:
    unordered_map<int, int> inorderIndexMap; // Map to store index of inorder elements
    int preorderIndex = 0;

    // Helper function to construct tree
    Node* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int start, int end) {
        if (start > end) return NULL;

        int rootValue = preorder[preorderIndex++];
        Node* root = new Node(rootValue);
        
        int inorderIndex = inorderIndexMap[rootValue];

        // Build left and right subtrees
        root->left = buildTreeHelper(preorder, inorder, start, inorderIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, inorderIndex + 1, end);

        return root;
    }

    // Function to build the tree from given inorder and preorder traversals
    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        inorderIndexMap.clear();
        preorderIndex = 0;
        
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            inorderIndexMap[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, inorder, 0, n - 1);
    }

    // Function to print postorder traversal
    void postorderTraversal(Node* root, vector<int> &postorder) {
        if (root == NULL) return;
        postorderTraversal(root->left, postorder);
        postorderTraversal(root->right, postorder);
        postorder.push_back(root->data);
    }
};


//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends