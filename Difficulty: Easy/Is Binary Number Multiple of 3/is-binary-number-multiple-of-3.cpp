//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int isDivisible(string s){
	    // Variables to keep track of sums for even and odd indexed bits
	    int odd_sum = 0, even_sum = 0;
	    
	    // Traverse the binary string
	    for (int i = 0; i < s.length(); i++) {
	        if (s[i] == '1') {  // Only consider '1' bits
	            if (i % 2 == 0) {
	                // Even index (0-based)
	                even_sum++;
	            } else {
	                // Odd index (0-based)
	                odd_sum++;
	            }
	        }
	    }
	    
	    // Check if the difference of the sums is divisible by 3
	    int diff = abs(even_sum - odd_sum);
	    return (diff % 3 == 0) ? 1 : 0;
	}
};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends