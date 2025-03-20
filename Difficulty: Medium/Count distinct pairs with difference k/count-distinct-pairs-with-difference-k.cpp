//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    int TotalPairs(vector<int> nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;

        // Count the frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Iterate through unique numbers
        for (auto& pair : freq) {
            int num = pair.first;

            if (k == 0) {
                // If k == 0, we need at least two occurrences of the same number
                if (pair.second > 1) {
                    count++;
                }
            } else {
                // Check if num + k exists in the set
                if (freq.count(num + k)) {
                    count++;
                }
            }
        }
        return count;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.TotalPairs(nums, k);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends