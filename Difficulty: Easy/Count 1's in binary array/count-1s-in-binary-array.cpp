//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
 public:
    // Function to count number of Ones in a sorted non-increasing binary array
    int countOnes(int arr[], int N) {
        int left = 0, right = N - 1, firstOneIndex = -1;

        // Binary search to find the first occurrence of 0
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == 1) {
                firstOneIndex = mid; // Store index of first 1
                left = mid + 1; // Move right to find last occurrence of 1
            } else {
                right = mid - 1; // Move left to find first occurrence of 0
            }
        }

        return firstOneIndex + 1; // Count of 1s = index of last 1 + 1
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        int *arr = new int[n]; 
        for(int i = 0; i < n; i++)
            cin>>arr[i];
            
        Solution ob;
        cout <<ob.countOnes(arr, n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends