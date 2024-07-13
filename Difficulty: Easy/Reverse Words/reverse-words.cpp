//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    // Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        vector<string> words;
        stringstream ss(S);
        string word;

        // Split the string into words using '.' as the delimiter
        while (getline(ss, word, '.')) {
            words.push_back(word);
        }
        
        // Reverse the order of words
        reverse(words.begin(), words.end());
        
        // Join the words with '.' as the separator
        string result;
        for (size_t i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i < words.size() - 1) {
                result += '.';
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends