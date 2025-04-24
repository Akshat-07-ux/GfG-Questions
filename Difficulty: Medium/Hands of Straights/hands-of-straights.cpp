//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        if (N % groupSize != 0) return false; // Can't divide evenly

        map<int, int> freq; // Sorted keys auto-magically handled
        for (int card : hand) {
            freq[card]++;
        }

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int start = it->first;
            int count = it->second;

            if (count > 0) {
                // Try to build a sequence from 'start' of length groupSize
                for (int i = 0; i < groupSize; ++i) {
                    if (freq[start + i] < count) {
                        return false; // Not enough cards to form the group
                    }
                    freq[start + i] -= count;
                }
            }
        }

        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends