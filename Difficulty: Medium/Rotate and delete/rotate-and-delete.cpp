//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        int sz = arr.size();
        
        for (int k = 1; k <= sz / 2; ++k) {
            // Step 1: Right-rotate the array by 1 (clockwise)
            int last = arr.back();  // Save the last element
            arr.pop_back();          // Remove the last element
            arr.insert(arr.begin(), last);  // Insert it at the beginning

            // Step 2: Delete the (n - k + 1)th element from the beginning
            int deleteIndex = arr.size() - k;  // (n - k + 1)th element
            arr.erase(arr.begin() + deleteIndex);
        }

        // Return the first element of the resulting array
        return arr[0];
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
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends