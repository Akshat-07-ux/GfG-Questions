//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k) {
	    // Map to store the first occurrence of a remainder
	    unordered_map<int, int> remainderMap;
	    
	    int maxLen = 0;
	    int prefixSum = 0;
	    
	    // To handle the case where the subarray starts from index 0
	    remainderMap[0] = -1;
	    
	    for (int i = 0; i < n; ++i) {
	        prefixSum += arr[i];
	        
	        // Compute the remainder of prefixSum when divided by k
	        int remainder = prefixSum % k;
	        
	        // If remainder is negative, convert it to positive
	        if (remainder < 0) {
	            remainder += k;
	        }
	        
	        // If the remainder has been seen before
	        if (remainderMap.find(remainder) != remainderMap.end()) {
	            // The subarray between the first occurrence and the current index has sum divisible by k
	            int subarrayLength = i - remainderMap[remainder];
	            maxLen = max(maxLen, subarrayLength);
	        } else {
	            // Store the first occurrence of the remainder
	            remainderMap[remainder] = i;
	        }
	    }
	    
	    return maxLen;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends