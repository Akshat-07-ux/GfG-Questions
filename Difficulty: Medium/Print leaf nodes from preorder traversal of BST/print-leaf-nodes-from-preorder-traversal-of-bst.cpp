class Solution {
  public:
    int idx;

    void findLeaves(vector<int>& preorder, int minVal, int maxVal, vector<int>& leaves) {
        if (idx >= preorder.size()) return;

        int val = preorder[idx];

        // If the value is out of current range, return
        if (val < minVal || val > maxVal) return;

        // Store the current value and move to next
        idx++;
        int currentIdx = idx;

        // Check left subtree
        findLeaves(preorder, minVal, val - 1, leaves);

        // Check right subtree
        findLeaves(preorder, val + 1, maxVal, leaves);

        // If no left or right child was processed, it's a leaf
        if (idx == currentIdx)
            leaves.push_back(val);
    }

    vector<int> leafNodes(vector<int>& preorder) {
        idx = 0;
        vector<int> leaves;
        findLeaves(preorder, INT_MIN, INT_MAX, leaves);
        return leaves;
    }
};