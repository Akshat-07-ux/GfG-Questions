//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    // Function to count subarrays with equal number of 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n) {
        unordered_map<int, int> prefixMap; // Stores prefix sum frequencies
        int prefixSum = 0;
        long long int count = 0;
        
        prefixMap[0] = 1; // Base case: If a prefix sum is 0, we found a valid subarray

        for (int i = 0; i < n; i++) {
            // Treat 0s as -1 to transform the problem into finding subarrays with sum 0
            prefixSum += (arr[i] == 0) ? -1 : 1;

            // If prefixSum was seen before, add the count of its occurrences to the result
            if (prefixMap.find(prefixSum) != prefixMap.end()) {
                count += prefixMap[prefixSum];
            }

            // Store/update prefix sum frequency
            prefixMap[prefixSum]++;
        }

        return count;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends