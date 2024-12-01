//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    // Function to return the sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int>>& matrix, int n)
    {
        int upperSum = 0, lowerSum = 0;

        // Traverse the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Add to upper triangle sum if j >= i (diagonal and above)
                if (j >= i) {
                    upperSum += matrix[i][j];
                }
                // Add to lower triangle sum if i >= j (diagonal and below)
                if (i >= j) {
                    lowerSum += matrix[i][j];
                }
            }
        }

        // Return the sums in a vector
        return {upperSum, lowerSum};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        vector<int> result = ob.sumTriangles(matrix,n);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends