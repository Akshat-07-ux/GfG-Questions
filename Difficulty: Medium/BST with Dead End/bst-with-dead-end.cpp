/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
   public:
    bool checkDeadEnd(Node* node, int minVal, int maxVal) {
        if (!node) return false;

        // If this is a leaf node and the allowed range collapses
        if (!node->left && !node->right) {
            if (minVal == maxVal) return true;
        }

        // Check recursively for left and right subtrees
        return checkDeadEnd(node->left, minVal, node->data - 1) ||
               checkDeadEnd(node->right, node->data + 1, maxVal);
    }

    bool isDeadEnd(Node *root) {
        return checkDeadEnd(root, 1, INT_MAX);
    }
};