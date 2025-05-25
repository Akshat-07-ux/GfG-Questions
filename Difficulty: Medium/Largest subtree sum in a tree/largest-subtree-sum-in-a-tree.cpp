// User function Template for C++

class Solution {
  public:
    // Function to find largest subtree sum.
    int findLargestSubtreeSum(Node* root) {
        int maxSum = INT_MIN;
        subtreeSum(root, maxSum);
        return maxSum;
    }

  private:
    // Helper function to compute subtree sums
    int subtreeSum(Node* node, int &maxSum) {
        if (node == nullptr) return 0;

        // Recursive sum of left and right subtrees
        int left = subtreeSum(node->left, maxSum);
        int right = subtreeSum(node->right, maxSum);

        // Total sum of current subtree
        int total = left + right + node->data;

        // Update maxSum if current total is greater
        maxSum = max(maxSum, total);

        // Return current subtree sum to parent
        return total;
    }
};