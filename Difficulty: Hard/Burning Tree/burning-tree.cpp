/*
class Node {
  public:
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
    // Function to map each node to its parent and find the target node.
    void markParents(Node* root, unordered_map<Node*, Node*>& parentTrack, Node* &targetNode, int target) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front(); q.pop();
            if (current->data == target) targetNode = current;
            if (current->left) {
                parentTrack[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parentTrack[current->right] = current;
                q.push(current->right);
            }
        }
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentTrack;  // Node to parent map
        unordered_map<Node*, bool> visited;       // Visited map to prevent re-burning
        Node* targetNode = nullptr;

        // Step 1: Fill parent map and locate target
        markParents(root, parentTrack, targetNode, target);

        // Step 2: BFS from target node
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool spread = false;

            for (int i = 0; i < size; i++) {
                Node* current = q.front(); q.pop();

                // Left Child
                if (current->left && !visited[current->left]) {
                    spread = true;
                    visited[current->left] = true;
                    q.push(current->left);
                }

                // Right Child
                if (current->right && !visited[current->right]) {
                    spread = true;
                    visited[current->right] = true;
                    q.push(current->right);
                }

                // Parent
                if (parentTrack[current] && !visited[parentTrack[current]]) {
                    spread = true;
                    visited[parentTrack[current]] = true;
                    q.push(parentTrack[current]);
                }
            }

            if (spread) time++;  // Only increment time if fire actually spreads
        }

        return time;
    }
};