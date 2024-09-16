//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    // Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n) {
        // Hash map to store the frequency of prefix sums.
        unordered_map<long long int, long long int> prefixSumMap;
        
        long long int prefix_sum = 0; // Initialize the prefix sum to 0.
        long long int count = 0; // Variable to store the count of subarrays.
        
        // Initialize the map with a base case where prefix_sum is 0 (for subarrays starting from index 0).
        prefixSumMap[0] = 1;
        
        // Traverse through the array.
        for (int i = 0; i < n; i++) {
            // Add the current element to the prefix sum.
            prefix_sum += arr[i];
            
            // If this prefix sum has been seen before, there are subarrays that sum to 0.
            if (prefixSumMap.find(prefix_sum) != prefixSumMap.end()) {
                // Add the frequency of this prefix sum to the count.
                count += prefixSumMap[prefix_sum];
            }
            
            // Increment the frequency of the current prefix sum.
            prefixSumMap[prefix_sum]++;
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
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends