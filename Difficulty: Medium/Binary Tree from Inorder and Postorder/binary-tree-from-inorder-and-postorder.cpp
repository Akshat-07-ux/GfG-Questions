//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
public:
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        // Map to store the index of each element in the inorder array for O(1) access
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        // Start building the tree using helper function
        int postIndex = postorder.size() - 1; // start from the last postorder element
        return buildTreeHelper(inorder, postorder, inorderMap, 0, inorder.size() - 1, postIndex);
    }

  private:
    Node* buildTreeHelper(const vector<int>& inorder, const vector<int>& postorder,
                          unordered_map<int, int>& inorderMap,
                          int inStart, int inEnd, int& postIndex) {
        // Base case: if there are no elements to construct the subtree
        if (inStart > inEnd) return NULL;

        // Pick the current root from postorder traversal using postIndex
        int rootVal = postorder[postIndex--];
        Node* root = new Node(rootVal);

        // Get the index of this root in inorder traversal
        int inIndex = inorderMap[rootVal];

        // Recursively build the right and left subtrees
        // Note: Build right subtree before left subtree since we are decrementing postIndex
        root->right = buildTreeHelper(inorder, postorder, inorderMap, inIndex + 1, inEnd, postIndex);
        root->left = buildTreeHelper(inorder, postorder, inorderMap, inStart, inIndex - 1, postIndex);

        return root;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> inorder;
        int number;
        while (ss >> number) {
            inorder.push_back(number);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> postorder;
        while (ss2 >> number) {
            postorder.push_back(number);
        }
        Solution obj;
        Node* root = obj.buildTree(inorder, postorder);
        preOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends