//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // Function to count the number of elements in the matrix that are <= mid
    int countSmallerOrEqual(vector<vector<int>>& matrix, int R, int C, int mid) {
        int count = 0;
        for (int i = 0; i < R; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        return count;
    }

    int median(vector<vector<int>> &matrix, int R, int C) {
        // Set the search range: smallest and largest elements in the matrix
        int low = 1, high = 2000; // As matrix[i][j] is in the range 1 to 2000
        
        int desired = (R * C) / 2 + 1;  // Index of the median element in 1-based indexing

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = countSmallerOrEqual(matrix, R, C, mid);

            // If there are enough elements <= mid, move to the left half
            if (count < desired) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends