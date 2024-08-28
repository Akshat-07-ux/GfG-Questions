//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int atoi(string s) {
        if (s.empty()) return -1;

        int result = 0;
        int sign = 1;
        int startIndex = 0;

        // Check for sign
        if (s[0] == '-') {
            sign = -1;
            startIndex = 1; // Start parsing from the next character
        }

        // Iterate through each character in the string
        for (int i = startIndex; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                result = result * 10 + (s[i] - '0');
            } else {
                // If a non-numeric character is found, return -1
                return -1;
            }
        }

        // Apply the sign to the result
        return result * sign;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		int ans=ob.atoi(s);
		cout<<ans<<endl;
	}
}
// } Driver Code Ends