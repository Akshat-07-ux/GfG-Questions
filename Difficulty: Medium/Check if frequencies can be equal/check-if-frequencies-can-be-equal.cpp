//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    bool sameFreq(string s) {
        unordered_map<char, int> freqMap;  // To store the frequency of each character
        
        // Step 1: Count the frequency of each character in the string
        for (char c : s) {
            freqMap[c]++;
        }
        
        unordered_map<int, int> freqCount;  // To store how many characters have a specific frequency
        
        // Step 2: Count how many times each frequency occurs
        for (auto it : freqMap) {
            freqCount[it.second]++;
        }
        
        // If there's only one frequency, all characters already have the same frequency
        if (freqCount.size() == 1) {
            return true;
        }
        
        // If there are more than 2 different frequencies, it's impossible to equalize
        if (freqCount.size() > 2) {
            return false;
        }
        
        // Step 3: Analyze the two distinct frequencies
        vector<pair<int, int>> freqVector(freqCount.begin(), freqCount.end());
        int f1 = freqVector[0].first, count1 = freqVector[0].second;
        int f2 = freqVector[1].first, count2 = freqVector[1].second;
        
        // Case where we can remove one character to make all frequencies equal
        if ((f1 == 1 && count1 == 1) || (f2 == 1 && count2 == 1)) {
            return true;  // We can remove the character with frequency 1 entirely
        }
        
        // Case where one frequency is exactly 1 more than the other and occurs only once
        if ((f1 == f2 + 1 && count1 == 1) || (f2 == f1 + 1 && count2 == 1)) {
            return true;
        }
        
        return false;  // If none of the above conditions hold, return false
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends