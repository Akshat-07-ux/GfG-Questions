//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // Map to store anagram groups: sorted string -> vector of {original string, index}
        unordered_map<string, vector<pair<string, int>>> anagramGroups;
        
        // Group strings by their sorted form, keeping track of original indices
        for(int i = 0; i < arr.size(); i++) {
            string sorted = arr[i];
            sort(sorted.begin(), sorted.end());
            anagramGroups[sorted].push_back({arr[i], i});
        }
        
        // Convert map to vector of vectors, preserving original order
        vector<vector<string>> result;
        // First, collect and sort the keys (sorted strings) lexicographically
        vector<string> sortedKeys;
        for(auto& group : anagramGroups) {
            sortedKeys.push_back(group.first);
        }
        sort(sortedKeys.begin(), sortedKeys.end());
        
        // Process groups in lexicographic order of their sorted form
        for(const string& key : sortedKeys) {
            auto& group = anagramGroups[key];
            // Sort the group by original indices to maintain order of appearance
            sort(group.begin(), group.end(), 
                 [](const pair<string, int>& a, const pair<string, int>& b) {
                     return a.second < b.second;
                 });
            
            // Extract just the strings in order
            vector<string> groupStrings;
            for(const auto& p : group) {
                groupStrings.push_back(p.first);
            }
            result.push_back(groupStrings);
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends