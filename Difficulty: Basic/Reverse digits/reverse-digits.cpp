//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    long long int reverse_digit(long long int n) {
        long long int reversedNum = 0;
        
        // Extract digits and reverse
        while (n > 0) {
            int lastDigit = n % 10;  // Get the last digit
            reversedNum = reversedNum * 10 + lastDigit;  // Append the last digit to the reversed number
            n /= 10;  // Remove the last digit from n
        }
        
        return reversedNum;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int n;
    	cin >> n;
    	Solution ob;
    	long long int  ans = ob.reverse_digit(n);
    	cout << ans <<"\n";
    }
	return 0;
}
// } Driver Code Ends