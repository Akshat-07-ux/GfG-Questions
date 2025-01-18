//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to count set bits in a number
    int countSetBits(int num) {
        int count = 0;
        while (num > 0) {
            count += (num & 1);
            num >>= 1;
        }
        return count;
    }

    // Function to check if a number is bleak
    int is_bleak(int n) {
        // Check for all numbers x in the range [n - log2(n), n)
        // log2(n) is the maximum number of set bits for numbers less than or equal to n
        for (int x = n - 1; x >= max(1, n - 32); x--) {
            if (x + countSetBits(x) == n) {
                return 0; // Not bleak
            }
        }
        return 1; // Bleak
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
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends