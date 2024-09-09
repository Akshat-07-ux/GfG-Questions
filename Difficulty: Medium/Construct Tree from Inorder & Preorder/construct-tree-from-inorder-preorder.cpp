//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
 private:
    Node* buildTreeHelper(int in[], int pre[], int inStart, int inEnd, int& preIndex, unordered_map<int, int>& inMap) {
        if (inStart > inEnd) return nullptr;

        Node* root = new Node(pre[preIndex++]);

        if (inStart == inEnd) return root;

        int inIndex = inMap[root->data];

        root->left = buildTreeHelper(in, pre, inStart, inIndex - 1, preIndex, inMap);
        root->right = buildTreeHelper(in, pre, inIndex + 1, inEnd, preIndex, inMap);

        return root;
    }

public:
    Node* buildTree(int in[], int pre[], int n) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < n; i++) {
            inMap[in[i]] = i;
        }

        int preIndex = 0;
        return buildTreeHelper(in, pre, 0, n - 1, preIndex, inMap);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends