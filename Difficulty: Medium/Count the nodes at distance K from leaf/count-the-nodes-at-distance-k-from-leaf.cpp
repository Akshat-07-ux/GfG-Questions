//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//Node Structure
/*struct NodeGiven a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes. A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly k.
{
	int data;
	Node *left, *right;
};*/

class Solution
{
public:
    // Helper function to count special nodes.
    void findSpecialNodes(Node* root, int k, vector<Node*>& path, unordered_set<Node*>& specialNodes) {
        if (!root) return;

        // Add current node to the path.
        path.push_back(root);

        // If it's a leaf node.
        if (!root->left && !root->right) {
            // Check if the path has a valid node at a distance k.
            if (path.size() > k) {
                specialNodes.insert(path[path.size() - k - 1]);
            }
        }

        // Recursively call for left and right subtrees.
        findSpecialNodes(root->left, k, path, specialNodes);
        findSpecialNodes(root->right, k, path, specialNodes);

        // Remove the current node from the path as we backtrack.
        path.pop_back();
    }

    // Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k) {
        unordered_set<Node*> specialNodes; // To store unique special nodes.
        vector<Node*> path; // To keep track of the current path.

        findSpecialNodes(root, k, path, specialNodes);

        // The size of the set gives the count of unique special nodes.
        return specialNodes.size();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s, ks;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, ks);
        int k=stoi(ks);
        Solution obj;
        cout<<obj.printKDistantfromLeaf(root, k)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}


// } Driver Code Ends