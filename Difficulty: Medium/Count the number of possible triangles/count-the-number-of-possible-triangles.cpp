//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    // Function to count the number of possible triangles.
    static int findNumberOfTriangles(int arr[], int n)
    {
        // Sort the array
        sort(arr, arr + n);
        
        int count = 0;
        
        // Fix the third side (largest side in the triangle)
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            
            // Use two pointers to find valid pairs
            while (i < j) {
                // If the sum of arr[i] and arr[j] is greater than arr[k],
                // then all pairs (arr[i], arr[i+1], ..., arr[j]) will form a valid triangle
                if (arr[i] + arr[j] > arr[k]) {
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}
// } Driver Code Ends