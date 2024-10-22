//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // Map to store frequency of prefix sums
        unordered_map<int, int> prefixMap;
        
        // Initialize the prefix sum to 0 (no elements yet)
        prefixMap[0] = 1;
        
        int count = 0;
        int prefixSum = 0;
        
        for (int num : arr) {
            // Update the prefix sum based on the current number
            if (num == x) {
                prefixSum += 1;
            } else if (num == y) {
                prefixSum -= 1;
            }
            
            // If this prefix sum has been seen before, it means there are
            // subarrays with the same occurrences of x and y.
            if (prefixMap.find(prefixSum) != prefixMap.end()) {
                count += prefixMap[prefixSum];
            }
            
            // Increment the count of the current prefix sum
            prefixMap[prefixSum]++;
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends