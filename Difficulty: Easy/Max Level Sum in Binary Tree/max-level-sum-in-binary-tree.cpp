/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution {
   public:
    int maxLevelSum(Node* root) {
        if (!root) return 0;

        int maxSum = root->data;
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;

            for (int i = 0; i < levelSize; ++i) {
                Node* curr = q.front();
                q.pop();
                levelSum += curr->data;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            maxSum = std::max(maxSum, levelSum);
        }

        return maxSum;
    }
};