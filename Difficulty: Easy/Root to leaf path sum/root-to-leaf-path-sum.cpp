//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
        // Base case: If the root is null, return false
        if (root == nullptr) {
            return false;
        }
        
        // If the current node is a leaf node, check if its value is equal to the target
        if (root->left == nullptr && root->right == nullptr) {
            return root->data == target;
        }
        
        // Recursively check the left and right subtrees
        bool leftPath = hasPathSum(root->left, target - root->data);
        bool rightPath = hasPathSum(root->right, target - root->data);
        
        // Return true if either the left or right path satisfies the condition
        return leftPath || rightPath;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int sum;
        scanf("%d ", &sum);
        // if (sum == 2) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool r = ob.hasPathSum(root, sum);
        if (r)
            cout << "true"
                 << "\n";
        else
            cout << "false"
                 << "\n";
    }
    return 0;
}

// } Driver Code Ends