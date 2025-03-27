//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    int maxOnes(std::vector<std::vector<int>>& Mat, int N, int M) {
        int maxRowIndex = -1;
        int maxCount = 0;

        for (int i = 0; i < N; ++i) {
            // Use binary search to find the first 1 in the row
            auto it = std::lower_bound(Mat[i].begin(), Mat[i].end(), 1);
            int count = M - std::distance(Mat[i].begin(), it);

            if (count > maxCount) {
                maxCount = count;
                maxRowIndex = i;
            }
        }

        return maxRowIndex;
    }
};


//{ Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends