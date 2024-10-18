//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<int> topK(int k, vector<int>& arr) {
        unordered_map<int, int> freqMap;
        
        // Step 1: Count the frequency of each element
        for (int num : arr) {
            freqMap[num]++;
        }
        
        // Step 2: Use a max-heap to store elements by frequency and value
        // The pair contains <frequency, element>. We want to sort by frequency first, then by element value.
        priority_queue<pair<int, int>> maxHeap;
        
        for (auto& entry : freqMap) {
            // We store (-frequency, -element) to ensure the priority queue sorts by frequency first, and for equal frequencies, the larger element comes first.
            maxHeap.push({entry.second, entry.first});
        }
        
        // Step 3: Extract the top k elements
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
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

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.topK(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends