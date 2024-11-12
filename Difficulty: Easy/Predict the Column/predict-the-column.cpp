//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
   public:
    // Function to count zeros in each column
    int columnWithMaxZeros(vector<vector<int>> &arr, int N) {
        int maxZeros = 0; // To store maximum number of zeros found
        int columnIndex = -1; // To store the index of the column with maximum zeros

        // Iterate through each column
        for (int col = 0; col < N; col++) {
            int zeroCount = 0;

            // Count zeros in the current column
            for (int row = 0; row < N; row++) {
                if (arr[row][col] == 0) {
                    zeroCount++;
                }
            }

            // Check if the current column has more zeros than previous ones
            if (zeroCount > maxZeros) {
                maxZeros = zeroCount;
                columnIndex = col;
            }
        }

        // If no zeros found in any column, return -1
        return (maxZeros == 0) ? -1 : columnIndex;
    }
};

//{ Driver Code Starts.
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    vector<vector<int>>arr(N,vector<int>(N));
	    // Taking elements input into the matrix
	    for(int i = 0;i<N;i++){
	        for(int j = 0;j<N;j++){
	            int x;
	            cin >> x; 
	            arr[i][j]=x;
	        }
	    }
	    Solution ob;
	    cout << ob.columnWithMaxZeros(arr,N) << endl;
	
cout << "~" << "\n";
}
	
	return 0;
}
// } Driver Code Ends