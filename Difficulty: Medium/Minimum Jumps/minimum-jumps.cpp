//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
 public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        // Edge case: If the array has only one element
        if (n == 1) return 0;

        // Edge case: If the first element is 0 and there are more than 1 elements
        if (arr[0] == 0) return -1;

        // Initialize variables
        int maxReach = arr[0];  // The farthest we can reach from the current index
        int steps = arr[0];     // Steps we can take before needing to make another jump
        int jumps = 1;          // We start by making the first jump
        
        // Traverse the array from the 1st index to the second-to-last index
        for (int i = 1; i < n; i++) {
            // If we've reached the last index
            if (i == n - 1) return jumps;

            // Update maxReach
            maxReach = max(maxReach, i + arr[i]);

            // Use a step to move forward
            steps--;

            // If no more steps are remaining, we need to make another jump
            if (steps == 0) {
                jumps++;  // Increment the number of jumps
                
                // If we can't move further, return -1
                if (i >= maxReach) return -1;

                // Reset steps to the number of steps we can take from the new position
                steps = maxReach - i;
            }
        }

        // If we haven't reached the last index, return -1
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
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends