//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x) {
        vector<int> arr1, arr2;

        // Flatten mat1 into arr1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr1.push_back(mat1[i][j]);
            }
        }

        // Flatten mat2 into arr2 (reverse order for two-pointer approach)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                arr2.push_back(mat2[i][j]);
            }
        }

        // Two-pointer approach
        int i = 0, j = 0, count = 0;
        while (i < n * n && j < n * n) {
            int sum = arr1[i] + arr2[j];

            if (sum == x) {
                count++;
                i++;
                j++;
            } else if (sum < x) {
                i++; // Increase sum
            } else {
                j++; // Decrease sum
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends