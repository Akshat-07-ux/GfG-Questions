// User function Template for C++

class Solution {
   public:
    int maxPathSum(Node* root) {
        if (root == nullptr) return 0;
        return dfs(root);
    }

  private:
    int dfs(Node* node) {
        // If node is NULL, return minimum value
        if (node == nullptr) return INT_MIN;

        // If node is a leaf, return its value
        if (node->left == nullptr && node->right == nullptr) {
            return node->data;
        }

        // Recurse on left and right subtrees
        int leftSum = dfs(node->left);
        int rightSum = dfs(node->right);

        // Return max path sum from leaf to this node
        return max(leftSum, rightSum) + node->data;
    }
};