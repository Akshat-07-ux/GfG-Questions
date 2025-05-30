/*
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
}; */

class Solution {
   public:
    int findMaxFork(Node* root, int k) {
        int ans = -1;  // Default if no such element exists
        while (root != nullptr) {
            if (root->data == k) {
                return k;  // Perfect match
            }
            else if (root->data < k) {
                ans = root->data;   // Potential answer
                root = root->right; // Try for a closer (larger) one
            }
            else {
                root = root->left;  // Too big, go smaller
            }
        }
        return ans;
    }
};