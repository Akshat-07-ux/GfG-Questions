//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> numIndex(n);

        // Create pairs of (element, index)
        for (int i = 0; i < n; ++i) {
            numIndex[i] = {nums[i], i};
        }

        // Sort pairs by element values
        sort(numIndex.begin(), numIndex.end());

        // To keep track of visited elements
        vector<bool> visited(n, false);
        int minSwaps = 0;

        for (int i = 0; i < n; ++i) {
            // If already visited or already in the correct position
            if (visited[i] || numIndex[i].second == i) {
                continue;
            }

            // Compute the size of the cycle
            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = numIndex[j].second;
                ++cycleSize;
            }

            // If cycle size is greater than 1, we need (cycleSize - 1) swaps
            if (cycleSize > 1) {
                minSwaps += (cycleSize - 1);
            }
        }

        return minSwaps;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends