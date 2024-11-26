//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int searchInsertK(vector<int> Arr, int N, int k) {
        int low = 0, high = N - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (Arr[mid] == k) {
                // If k is found, return its index
                return mid;
            } else if (Arr[mid] < k) {
                // Move to the right half
                low = mid + 1;
            } else {
                // Move to the left half
                high = mid - 1;
            }
        }

        // If not found, low is the position where k should be inserted
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
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends