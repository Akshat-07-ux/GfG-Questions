//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
public:
    // Helper function using recursion to solve Josephus problem.
    int josephusUtil(int n, int k) {
        // Base case: only one person left, so they are the survivor.
        if (n == 1) {
            return 0;
        }
        // Recursive case: f(n-1, k) is shifted by k positions and wrapped around using % n.
        return (josephusUtil(n - 1, k) + k) % n;
    }

    // Main function that adjusts result for 1-based indexing.
    int josephus(int n, int k) {
        // Since the recursive solution is 0-based, we add 1 to convert it to 1-based.
        return josephusUtil(n, k) + 1;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends