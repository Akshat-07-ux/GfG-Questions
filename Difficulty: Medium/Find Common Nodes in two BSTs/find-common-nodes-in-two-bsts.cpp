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
    Node* root = new Node(stoi(ip[0]));
        
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
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends


class Solution
{
 public:
    void inorderTraversal(Node* root, vector<int>& nodes) {
        if (!root) return;
        
        // Perform inorder traversal to get sorted nodes
        inorderTraversal(root->left, nodes);
        nodes.push_back(root->data);
        inorderTraversal(root->right, nodes);
    }
    
    vector<int> findCommon(Node *root1, Node *root2)
    {
        // Vectors to store inorder traversals of both trees
        vector<int> nodes1, nodes2;
        
        // Perform inorder traversal to get sorted nodes for both trees
        inorderTraversal(root1, nodes1);
        inorderTraversal(root2, nodes2);
        
        // Vector to store common nodes
        vector<int> common;
        
        // Two-pointer approach to find common nodes
        int i = 0, j = 0;
        while (i < nodes1.size() && j < nodes2.size()) {
            if (nodes1[i] == nodes2[j]) {
                // Common node found
                common.push_back(nodes1[i]);
                i++;
                j++;
            }
            else if (nodes1[i] < nodes2[j]) {
                // Move pointer in first tree
                i++;
            }
            else {
                // Move pointer in second tree
                j++;
            }
        }
        
        return common;
    }
};




//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root1 = buildTree(s);

        getline(cin,s);
        Node* root2 = buildTree(s);
        Solution ob;
        vector <int> res = ob.findCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout<< endl;
    
cout << "~" << "\n";
}

	return 1;
}
// } Driver Code Ends