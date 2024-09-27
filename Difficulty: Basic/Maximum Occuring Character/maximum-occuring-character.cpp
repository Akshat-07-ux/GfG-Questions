//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
 public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str) {
        // Array to store the frequency of each character (26 for 'a' to 'z').
        int freq[26] = {0};
        
        // Calculate frequency of each character in the string.
        for (char ch : str) {
            freq[ch - 'a']++;
        }
        
        // Variables to track the maximum frequency and the corresponding character.
        int maxFreq = 0;
        char result = 'a';  // Initialize result with 'a' as a lexicographically smallest option.
        
        // Traverse the frequency array to find the maximum occurring character.
        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                result = 'a' + i;
            } else if (freq[i] == maxFreq) {
                // If there is a tie, select the lexicographically smaller character.
                if (result > ('a' + i)) {
                    result = 'a' + i;
                }
            }
        }
        
        // Return the character with the maximum frequency.
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends