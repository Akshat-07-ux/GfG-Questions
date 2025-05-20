/*
Structure of the node of the binary tree is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
*/
class Solution {
public:
    int getLevel(struct Node *node, int target) {
        if (!node) return 0;

        queue<Node*> q;
        q.push(node);
        int level = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();

                if (current->data == target)
                    return level;

                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }

            level++;
        }

        return 0; // target not found
    }
};
