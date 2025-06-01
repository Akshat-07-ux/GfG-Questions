/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
   public:
    int maxNodeLevel(Node *root) {
        if (!root) return -1;

        queue<Node*> q;
        q.push(root);

        int level = 0;
        int maxLevel = 0;
        int maxCount = 0;

        while (!q.empty()) {
            int size = q.size(); // Number of nodes at current level

            if (size > maxCount) {
                maxCount = size;
                maxLevel = level;
            }

            for (int i = 0; i < size; ++i) {
                Node* current = q.front();
                q.pop();

                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }

            level++;
        }

        return maxLevel;
    }
};