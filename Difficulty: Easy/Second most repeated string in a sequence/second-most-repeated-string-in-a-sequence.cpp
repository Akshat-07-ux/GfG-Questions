//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string secFrequent(string arr[], int n) {
        // Hash map to store the frequency of each string
        unordered_map<string, int> freqMap;

        // Count the frequency of each string
        for (int i = 0; i < n; i++) {
            freqMap[arr[i]]++;
        }

        // Find the highest and second highest frequencies
        int maxFreq = 0, secondMaxFreq = 0;
        for (const auto& entry : freqMap) {
            if (entry.second > maxFreq) {
                secondMaxFreq = maxFreq;
                maxFreq = entry.second;
            } else if (entry.second > secondMaxFreq && entry.second < maxFreq) {
                secondMaxFreq = entry.second;
            }
        }

        // Find the string with the second highest frequency
        for (const auto& entry : freqMap) {
            if (entry.second == secondMaxFreq) {
                return entry.first;
            }
        }

        // If no second most frequent string exists
        return "";
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    
cout << "~" << "\n";
}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends