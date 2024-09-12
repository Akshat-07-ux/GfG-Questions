//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorResult = 0;
        
        // Step 1: XOR all numbers to get xorResult = x ^ y
        for (int num : nums) {
            xorResult ^= num;
        }
        
        // Step 2: Find a bit that is set in xorResult
        int differentiatingBit = xorResult & -xorResult; // This isolates the rightmost set bit
        
        // Step 3: Partition numbers into two groups and find the two unique numbers
        int num1 = 0, num2 = 0;
        for (int num : nums) {
            if (num & differentiatingBit) {
                num1 ^= num; // XOR numbers with the differentiating bit set
            } else {
                num2 ^= num; // XOR numbers without the differentiating bit
            }
        }
        
        // Step 4: Sort the results and return
        if (num1 > num2) {
            swap(num1, num2);
        }
        
        return {num1, num2};
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
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends