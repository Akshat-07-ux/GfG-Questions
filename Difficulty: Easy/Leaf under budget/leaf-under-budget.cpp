//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
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
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

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
        if (currVal != "N")
        {

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

/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    int getCount(Node *root, int budget) {
        if (!root) return 0;

        queue<pair<Node*, int>> q; // (Node, Level)
        vector<int> leafCosts;
        q.push(make_pair(root, 1)); // Start with root at level 1

        // Level order traversal
        while (!q.empty()) {
            pair<Node*, int> front = q.front();
            q.pop();

            Node* node = front.first;
            int level = front.second;

            // If it's a leaf node, store the cost
            if (!node->left && !node->right) {
                leafCosts.push_back(level);
            }

            // Push children to queue with incremented level
            if (node->left) q.push(make_pair(node->left, level + 1));
            if (node->right) q.push(make_pair(node->right, level + 1));
        }

        // Sort leaf nodes by cost (ascending order) to maximize count
        sort(leafCosts.begin(), leafCosts.end());

        int count = 0;
        for (int cost : leafCosts) {
            if (budget >= cost) {
                budget -= cost;
                count++;
            } else {
                break; // Stop when budget is exhausted
            }
        }

        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        int res = obj.getCount(root, k);
        cout << res << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends