//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        if(str1.length() != str2.length())
            return false;
        
        if(str1.length() < 2)
            return str1 == str2;  // For strings of length 1 or 2, just check equality
        
        // Clockwise rotation by 2 places
        string clock_rot = str1.substr(str1.length() - 2) + str1.substr(0, str1.length() - 2);
        
        // Counterclockwise rotation by 2 places
        string anti_clock_rot = str1.substr(2) + str1.substr(0, 2);
        
        // Check if either rotation matches str2
        return (str2 == clock_rot || str2 == anti_clock_rot);
    }
};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends