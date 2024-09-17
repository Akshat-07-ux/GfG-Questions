//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2) {
        // Ensure array1 is the smaller array
        if (array1.size() > array2.size()) {
            return MedianOfArrays(array2, array1);
        }

        int m = array1.size();
        int n = array2.size();
        int imin = 0, imax = m, half_len = (m + n + 1) / 2;

        while (imin <= imax) {
            int i = (imin + imax) / 2;
            int j = half_len - i;

            if (i < m && j > 0 && array2[j - 1] > array1[i]) {
                // i is too small, increase it
                imin = i + 1;
            } else if (i > 0 && j < n && array1[i - 1] > array2[j]) {
                // i is too large, decrease it
                imax = i - 1;
            } else {
                // i is perfect
                int max_of_left, min_of_right;

                if (i == 0) {
                    max_of_left = array2[j - 1];
                } else if (j == 0) {
                    max_of_left = array1[i - 1];
                } else {
                    max_of_left = max(array1[i - 1], array2[j - 1]);
                }

                if ((m + n) % 2 == 1) {
                    return max_of_left;
                }

                if (i == m) {
                    min_of_right = array2[j];
                } else if (j == n) {
                    min_of_right = array1[i];
                } else {
                    min_of_right = min(array1[i], array2[j]);
                }

                return (max_of_left + min_of_right) / 2.0;
            }
        }

        throw invalid_argument("Input arrays are not sorted or invalid.");
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends