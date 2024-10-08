//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // Start from the top-right corner
	    int row = 0, col = M - 1;
	    
	    // Traverse the matrix
	    while (row < N && col >= 0) {
	        if (mat[row][col] == X) {
	            return 1;  // Element found
	        }
	        else if (mat[row][col] > X) {
	            col--;  // Move left
	        } else {
	            row++;  // Move down
	        }
	    }
	    
	    return 0;  // Element not found
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends