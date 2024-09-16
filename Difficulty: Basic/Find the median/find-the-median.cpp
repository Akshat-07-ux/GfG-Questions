//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
public:
    int find_median(vector<int> v) {
        // Sort the array
        sort(v.begin(), v.end());

        int n = v.size();
        if (n % 2 == 1) {
            // If the number of elements is odd, return the middle element
            return v[n / 2];
        } else {
            // If the number of elements is even, return the floor of the average
            int mid1 = v[n / 2 - 1];
            int mid2 = v[n / 2];
            return (mid1 + mid2) / 2; // Use integer division for floor value
        }
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends