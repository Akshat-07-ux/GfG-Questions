//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    
cout << "~" << "\n";
}
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



// Structure to represent elements in the heap
struct HeapNode {
    int value; // Value of the matrix element
    int row;   // Row index of the matrix element
    int col;   // Column index of the matrix element
};

struct Compare {
    bool operator()(HeapNode const& a, HeapNode const& b) {
        return a.value > b.value; // Min-heap
    }
};

int kthSmallest(int mat[MAX][MAX], int n, int k) {
    // Min-heap to store the elements of the first column
    priority_queue<HeapNode, vector<HeapNode>, Compare> minHeap;

    // Insert the first element of each row into the heap
    for (int i = 0; i < n; i++) {
        minHeap.push({mat[i][0], i, 0});
    }

    // Extract elements from the heap k times
    int count = 0;
    int result = 0;
    while (count < k) {
        HeapNode current = minHeap.top();
        minHeap.pop();
        result = current.value; // Smallest element

        // Move to the next column in the same row
        if (current.col + 1 < n) {
            minHeap.push({mat[current.row][current.col + 1], current.row, current.col + 1});
        }

        count++;
    }

    return result; // kth smallest element
}