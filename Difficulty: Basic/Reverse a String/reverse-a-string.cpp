//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    string reverseWord(string str)
    {
        int left = 0;
        int right = str.length() - 1;
        
        while (left < right) {
            // Swap characters at left and right indices
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            
            // Move the pointers towards the center
            left++;
            right--;
        }
        
        return str;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends