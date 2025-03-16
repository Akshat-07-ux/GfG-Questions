//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0; // Already at the last index
        if (arr[0] == 0) return -1; // Can't move anywhere

        int maxReach = arr[0]; // Max index reachable
        int steps = arr[0]; // Steps we can still take
        int jumps = 1; // Number of jumps taken

        for (int i = 1; i < n; i++) {
            if (i == n - 1) return jumps; // Reached the last index
            
            maxReach = max(maxReach, i + arr[i]); // Update max reachable index
            steps--; // Use a step

            if (steps == 0) { // Need to jump
                jumps++;
                if (i >= maxReach) return -1; // Can't move further
                steps = maxReach - i; // Update steps for the next jump
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends