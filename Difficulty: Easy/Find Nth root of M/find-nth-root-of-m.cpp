//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int NthRoot(int n, int m) {
        if (m == 1) return 1;  // The nth root of 1 is always 1 for any n

        long long low = 1, high = m;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            // Calculate mid^n using pow function
            long long power = 1;
            for (int i = 0; i < n; ++i) {
                if (power > m / mid) {  // To prevent overflow
                    power = m + 1;  // Break out of the loop if overflow is detected
                    break;
                }
                power *= mid;
            }

            if (power == m) {
                return mid;
            } else if (power < m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;  // If no exact nth root found
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends