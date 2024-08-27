//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    // Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S) {
        unordered_map<char, int> freqMap;
        
        // Count the frequency of each character in the string
        for (char ch : S) {
            freqMap[ch]++;
        }

        // Find the first character with a frequency of 1
        for (char ch : S) {
            if (freqMap[ch] == 1) {
                return ch;
            }
        }

        // If no non-repeating character is found, return '$'
        return '$';
    }
};


//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends