//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_set<int> elementsInWindow;

        for (int i = 0; i < arr.size(); i++) {
            // If the element is already in the set, we found a duplicate within k distance
            if (elementsInWindow.find(arr[i]) != elementsInWindow.end()) {
                return true;
            }
            
            // Add the current element to the set
            elementsInWindow.insert(arr[i]);

            // If the size of the window exceeds k, remove the element that is out of range
            if (i >= k) {
                elementsInWindow.erase(arr[i - k]);
            }
        }

        // No duplicates within k distance found
        return false;
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
        int k = stoi(ks);
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends