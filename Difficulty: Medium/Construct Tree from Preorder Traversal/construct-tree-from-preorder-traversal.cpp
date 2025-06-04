/*Structure of the Node of the binary tree is as
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
*/

Node* constructTreeUtil(int pre[], char preLN[], int& index, int n) {
    // Base case
    if (index >= n) return nullptr;

    // Create the current node
    Node* root = new Node(pre[index]);
    
    // If current node is a leaf, return it
    if (preLN[index] == 'L') {
        return root;
    }

    // Else, it's an internal node (non-leaf), so construct left and right subtrees
    index++;
    root->left = constructTreeUtil(pre, preLN, index, n);
    index++;
    root->right = constructTreeUtil(pre, preLN, index, n);

    return root;
}

Node* constructTree(int n, int pre[], char preLN[]) {
    int index = 0;
    return constructTreeUtil(pre, preLN, index, n);
}
