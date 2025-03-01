//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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

/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
class Solution{
public:
    vector<int> verticalSum(Node *root) {
        if (!root) return {}; // If tree is empty, return an empty vector

        // Map to store the sum of nodes at each horizontal distance
        map<int, int> verticalMap;
        queue<pair<Node*, int>> q; // Queue to store (node, horizontal distance)

        q.push({root, 0}); // Start with root at horizontal distance 0

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            Node* node = temp.first;
            int hd = temp.second; // Horizontal Distance

            // Update sum at this horizontal distance
            verticalMap[hd] += node->data;

            // Traverse left and right subtrees with updated horizontal distance
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        // Extract sums from the map in sorted order of horizontal distance
        vector<int> result;
        for (auto it : verticalMap) {
            result.push_back(it.second);
        }

        return result;
    }
};


//{ Driver Code Starts.
int main() 
{
    
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        vector <int> res = obj.verticalSum(root);
        for (int i : res) cout << i << " ";
        cout<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends