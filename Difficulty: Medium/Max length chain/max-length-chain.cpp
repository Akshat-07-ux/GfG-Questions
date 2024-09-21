//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    // Function to find the length of the longest chain
    int maxChainLen(struct val p[], int n) {
        // Step 1: Sort pairs based on the second element
        std::sort(p, p + n, [](const val &a, const val &b) {
            return a.second < b.second;
        });

        // Step 2: Initialize variables for chain length and the end of the last pair
        int chainLength = 1; // at least one pair can always be selected
        int lastEnd = p[0].second;

        // Step 3: Iterate through sorted pairs
        for (int i = 1; i < n; i++) {
            // If the current pair can be added to the chain
            if (p[i].first > lastEnd) {
                chainLength++;
                lastEnd = p[i].second; // Update the end of the last pair
            }
        }

        return chainLength; // Return the length of the longest chain
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends