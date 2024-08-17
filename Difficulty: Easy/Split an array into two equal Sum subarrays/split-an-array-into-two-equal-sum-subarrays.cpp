//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    bool canSplit(vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);  // Calculate the total sum of the array

        // If the total sum is odd, it's impossible to split it into two equal parts
        if (totalSum % 2 != 0) {
            return false;
        }

        int targetSum = totalSum / 2;
        int runningSum = 0;

        // Iterate through the array and maintain a running sum
        for (int i = 0; i < arr.size(); ++i) {
            runningSum += arr[i];

            // If the running sum equals half of the total sum, we can split the array
            if (runningSum == targetSum) {
                return true;
            }
        }

        // If no valid split is found, return false
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends