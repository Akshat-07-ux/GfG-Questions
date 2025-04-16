//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        vector<int> freq(26, 0);

        // Count frequency of each task
        for (char t : tasks) {
            freq[t - 'A']++;
        }

        // Get the max frequency
        int maxFreq = *max_element(freq.begin(), freq.end());

        // Count how many tasks have the same max frequency
        int maxCount = 0;
        for (int f : freq) {
            if (f == maxFreq) maxCount++;
        }

        // Core formula:
        // (maxFreq - 1) * (K + 1) + maxCount
        int partCount = maxFreq - 1;
        int partLength = K + 1;
        int emptySlots = partCount * partLength + maxCount;

        // The final answer is either that formula, or total tasks (if we can pack them tighter)
        return max(N, emptySlots);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends