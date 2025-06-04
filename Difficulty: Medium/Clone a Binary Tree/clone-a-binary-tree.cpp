/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

class Solution {
  public:
    unordered_map<Node*, Node*> nodeMap;

    // Step 1: Clone left and right, build the mapping
    Node* cloneStructure(Node* root) {
        if (!root) return nullptr;

        Node* cloned = new Node(root->data);
        nodeMap[root] = cloned;

        cloned->left = cloneStructure(root->left);
        cloned->right = cloneStructure(root->right);

        return cloned;
    }

    // Step 2: Set random pointers using the map
    void setRandomPointers(Node* original) {
        if (!original) return;

        Node* cloned = nodeMap[original];
        cloned->random = original->random ? nodeMap[original->random] : nullptr;

        setRandomPointers(original->left);
        setRandomPointers(original->right);
    }

    Node* cloneTree(Node* root) {
        if (!root) return nullptr;

        Node* clonedRoot = cloneStructure(root);
        setRandomPointers(root);

        return clonedRoot;
    }
};