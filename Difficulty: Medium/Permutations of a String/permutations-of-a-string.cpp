//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<string> findPermutation(string &s) {
        vector<string> result;
        unordered_set<string> uniquePermutations; // To store unique permutations
        
        // Sort the string to ensure the permutations are generated in order
        sort(s.begin(), s.end());

        do {
            // If this permutation is not already in the set, add it to the result
            if (uniquePermutations.find(s) == uniquePermutations.end()) {
                result.push_back(s);
                uniquePermutations.insert(s);
            }
        } while (next_permutation(s.begin(), s.end())); // Generate all permutations

        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends