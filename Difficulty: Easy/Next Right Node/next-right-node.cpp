/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
 public:
    Node* nextRight(Node* root, int key) {
        if (!root) return new Node(-1);

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                Node* curr = q.front();
                q.pop();

                // If current node is the key, return the next node in queue if same level
                if (curr->data == key) {
                    if (i == size - 1)
                        return new Node(-1); // No node to the right
                    else
                        return q.front(); // Next node in the same level
                }

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        // If key is not found
        return new Node(-1);
    }
};