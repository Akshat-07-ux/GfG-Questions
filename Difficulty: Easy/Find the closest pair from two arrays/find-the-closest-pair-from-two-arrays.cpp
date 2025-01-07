//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        int i = 0, j = m - 1;
        int closestDiff = INT_MAX;
        int closestA = 0, closestB = 0;

        while (i < n && j >= 0) {
            int sum = arr[i] + brr[j];
            int diff = abs(x - sum);

            // Update closest pair if a closer sum is found
            if (diff < closestDiff) {
                closestDiff = diff;
                closestA = arr[i];
                closestB = brr[j];
            }

            // Move pointers
            if (sum < x) {
                i++;  // Increase sum by moving the left pointer right
            } else {
                j--;  // Decrease sum by moving the right pointer left
            }
        }

        return {closestA, closestB};
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends