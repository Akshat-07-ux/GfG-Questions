/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution {
public:
    // Helper to map child -> parent and find target node
    void markParents(Node* root, std::unordered_map<Node*, Node*>& parentMap, Node*& target, int src) {
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->data == src)
                target = curr;

            if (curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    int ladoos(Node* root, int src, int k) {
        std::unordered_map<Node*, Node*> parentMap;
        Node* target = nullptr;

        markParents(root, parentMap, target, src);

        std::unordered_set<Node*> visited;
        std::queue<std::pair<Node*, int>> q;
        q.push({target, 0});
        visited.insert(target);

        int totalLadoos = 0;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            Node* curr = front.first;
            int dist = front.second;

            if (dist > k) break;

            totalLadoos += curr->data;

            if (curr->left && visited.find(curr->left) == visited.end()) {
                q.push({curr->left, dist + 1});
                visited.insert(curr->left);
            }

            if (curr->right && visited.find(curr->right) == visited.end()) {
                q.push({curr->right, dist + 1});
                visited.insert(curr->right);
            }

            if (parentMap.find(curr) != parentMap.end() && visited.find(parentMap[curr]) == visited.end()) {
                q.push({parentMap[curr], dist + 1});
                visited.insert(parentMap[curr]);
            }
        }

        return totalLadoos;
    }
};