//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *right, *down;

    Node(int x) {
        data = x;
        right = NULL;
        down = NULL;
    }
};


// } Driver Code Ends
/*structure of the node of the linked list is as

struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n = mat.size();  // size of the matrix

        // Create a 2D array of Node* to store the address of each node
        vector<vector<Node*>> nodeArr(n, vector<Node*>(n, NULL));

        // Step 1: Create all nodes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                nodeArr[i][j] = new Node(mat[i][j]);  // Create a new node for each matrix element
            }
        }

        // Step 2: Link the nodes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Link to the right node
                if (j + 1 < n) {
                    nodeArr[i][j]->right = nodeArr[i][j + 1];
                }
                // Link to the down node
                if (i + 1 < n) {
                    nodeArr[i][j]->down = nodeArr[i + 1][j];
                }
            }
        }

        // Return the head of the linked matrix (top-left corner node)
        return nodeArr[0][0];
    }
};

//{ Driver Code Starts.

void display(Node* head) {
    Node* Rp;
    Node* Dp = head;
    while (Dp) {
        Rp = Dp;
        while (Rp) {
            cout << Rp->data << " ";
            if (Rp->right)
                cout << Rp->right->data << " ";
            else
                cout << "null ";
            if (Rp->down)
                cout << Rp->down->data << " ";
            else
                cout << "null ";
            Rp = Rp->right;
        }
        Dp = Dp->down;
    }
}

// Driver program
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To handle new line after integer input

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;

        // Read the first row of the matrix
        while (ss >> num) {
            nums.push_back(num);
        }

        int n = nums.size();
        vector<vector<int>> mat(n, vector<int>(n));
        mat[0] = nums;

        // Read the remaining rows of the matrix
        for (int i = 1; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<int> nums;
            int num;

            // Read the first row of the matrix
            while (ss >> num) {
                nums.push_back(num);
            }

            mat[i] = nums;
        }

        Solution ob;
        Node* head = ob.constructLinkedMatrix(mat);
        if (!head) {
            cout << "-1\n";
        } else {
            display(head);
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends