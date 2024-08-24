//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        // If there are no students or only one packet to distribute, no difference
        if (m == 0 || n == 0)
            return 0;

        // Sort the array to arrange the chocolates in increasing order
        sort(a.begin(), a.end());
        
        // Initialize the minimum difference to a large value
        long long min_diff = LLONG_MAX;

        // Iterate through the array with a window of size m
        for (long long i = 0; i + m - 1 < n; i++) {
            long long diff = a[i + m - 1] - a[i];  // Calculate difference for the current window
            min_diff = min(min_diff, diff);       // Update the minimum difference if current is smaller
        }

        return min_diff;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends