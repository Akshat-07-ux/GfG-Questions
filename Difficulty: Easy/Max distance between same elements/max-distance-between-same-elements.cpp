//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> first_occurrence;
        int max_dist = 0;
        
        for (int i = 0; i < arr.size(); ++i) {
            // Check if the element has already appeared
            if (first_occurrence.find(arr[i]) == first_occurrence.end()) {
                // Record the first occurrence of the element
                first_occurrence[arr[i]] = i;
            } else {
                // Calculate the distance and update max_dist if necessary
                max_dist = max(max_dist, i - first_occurrence[arr[i]]);
            }
        }
        
        return max_dist;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends