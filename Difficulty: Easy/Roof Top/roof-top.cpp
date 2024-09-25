//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
 public:
    // Function to find the maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        int maxSteps = 0;  // To track the maximum number of consecutive steps
        int currentSteps = 0;  // To track the current number of consecutive steps

        // Traverse the array and compare consecutive elements
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                // If the next building is taller, increase the step count
                currentSteps++;
                maxSteps = max(maxSteps, currentSteps);  // Update maximum steps if needed
            } else {
                // If not, reset the current step count
                currentSteps = 0;
            }
        }

        return maxSteps;  // Return the maximum steps found
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.maxStep(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends