//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<int> sortByFreq(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Count the frequency of each element
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for (int num : arr) {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }
        
        // Step 2: Create buckets for each frequency
        vector<vector<int>> buckets(maxFreq + 1);
        for (const auto& pair : freq) {
            buckets[pair.second].push_back(pair.first);
        }
        
        // Step 3: Sort elements in each bucket
        for (auto& bucket : buckets) {
            sort(bucket.begin(), bucket.end());
        }
        
        // Step 4: Reconstruct the sorted array
        vector<int> result;
        for (int i = maxFreq; i > 0; i--) {
            for (int num : buckets[i]) {
                result.insert(result.end(), i, num);
            }
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

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends