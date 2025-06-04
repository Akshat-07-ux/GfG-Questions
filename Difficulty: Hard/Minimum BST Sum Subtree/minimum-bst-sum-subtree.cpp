// Structure of the Node is assumed to be:
// struct Node {
//     int data;
//     Node *left, *right;
// };

class Solution {
    int minLen;

    struct Info {
        bool isBST;
        int sum;
        int size;
        int minVal;
        int maxVal;

        Info(bool b, int s, int sz, int mi, int ma) :
            isBST(b), sum(s), size(sz), minVal(mi), maxVal(ma) {}
    };

    Info dfs(Node* node, int target) {
        if (!node)
            return Info(true, 0, 0, INT_MAX, INT_MIN);

        Info left = dfs(node->left, target);
        Info right = dfs(node->right, target);

        // Check if current subtree is BST
        if (left.isBST && right.isBST && node->data > left.maxVal && node->data < right.minVal) {
            int sum = node->data + left.sum + right.sum;
            int size = 1 + left.size + right.size;
            int minVal = min(node->data, left.minVal);
            int maxVal = max(node->data, right.maxVal);

            if (sum == target)
                minLen = min(minLen, size);

            return Info(true, sum, size, minVal, maxVal);
        }

        // Not a BST
        return Info(false, 0, 0, 0, 0);
    }

public:
    int minSubtreeSumBST(int target, Node *root) {
        minLen = INT_MAX;
        dfs(root, target);
        return minLen == INT_MAX ? -1 : minLen;
    }
};
