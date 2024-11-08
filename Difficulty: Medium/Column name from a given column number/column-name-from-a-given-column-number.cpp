//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
  public:
    string colName(long long int n) {
        string result = "";

        while (n > 0) {
            // Find the remainder
            int remainder = (n - 1) % 26;
            // Map remainder to corresponding letter (0 -> 'A', ..., 25 -> 'Z')
            char ch = 'A' + remainder;
            result += ch;
            // Update n for the next iteration
            n = (n - 1) / 26;
        }

        // Reverse the result string as we constructed it backwards
        reverse(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	
cout << "~" << "\n";
}
}

// } Driver Code Ends