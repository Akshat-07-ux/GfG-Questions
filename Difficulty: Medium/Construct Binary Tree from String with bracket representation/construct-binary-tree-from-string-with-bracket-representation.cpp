// User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/

class Solution {
 public:
    // Helper function to build the tree
    Node* buildTree(const string &str, int &i) {
        if (i >= str.length())
            return nullptr;

        // Read integer (handle negative as well)
        int num = 0;
        bool neg = false;

        if (str[i] == '-') {
            neg = true;
            i++;
        }

        while (i < str.size() && isdigit(str[i])) {
            num = num * 10 + (str[i] - '0');
            i++;
        }

        if (neg)
            num = -num;

        Node* root = new Node(num);

        // Check for left subtree
        if (i < str.size() && str[i] == '(') {
            i++; // skip '('
            if (str[i] != ')') { // if not an empty subtree
                root->left = buildTree(str, i);
            }
            i++; // skip ')'
        }

        // Check for right subtree
        if (i < str.size() && str[i] == '(') {
            i++; // skip '('
            if (str[i] != ')') { // if not an empty subtree
                root->right = buildTree(str, i);
            }
            i++; // skip ')'
        }

        return root;
    }

    // Main function to be called
    Node* treeFromString(string str) {
        int i = 0;
        return buildTree(str, i);
    }
};