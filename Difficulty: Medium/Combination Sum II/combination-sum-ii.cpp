//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
public:
    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort the array to handle duplicates easily
        sort(arr.begin(), arr.end());
        
        // Call the recursive function
        backtrack(arr, target, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int> &arr, int target, int index, vector<int> &current, vector<vector<int>> &result) {
        if (target == 0) {
            result.push_back(current); // Found a valid combination
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            // Skip duplicates
            if (i > index && arr[i] == arr[i - 1]) continue;

            // Stop if the number is greater than the remaining target
            if (arr[i] > target) break;

            // Include arr[i] in the combination
            current.push_back(arr[i]);
            backtrack(arr, target - arr[i], i + 1, current, result); // Move to the next index
            current.pop_back(); // Backtrack
        }
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
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        vector<vector<int>> ans = ob.uniqueCombinations(arr, sum);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                sort(ans[i].begin(), ans[i].end());
            }
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends