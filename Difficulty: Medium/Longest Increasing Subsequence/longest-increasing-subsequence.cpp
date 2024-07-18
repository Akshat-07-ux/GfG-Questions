//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
   public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> tails(n, 0);
        int len = 1;
        tails[0] = a[0];
        
        for (int i = 1; i < n; i++) {
            if (a[i] < tails[0]) {
                tails[0] = a[i];
            } else if (a[i] > tails[len-1]) {
                tails[len++] = a[i];
            } else {
                int pos = lower_bound(tails.begin(), tails.begin() + len, a[i]) - tails.begin();
                tails[pos] = a[i];
            }
        }
        
        return len;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends