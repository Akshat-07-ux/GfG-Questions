//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Sort the array to get elements in ascending order
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        vector<int> result;
        
        // Use two pointers to pick elements from both ends of the sorted array
        int left = 0, right = n - 1;
        while (left <= right) {
            if (left <= right) result.push_back(arr[right--]); // Pick largest
            if (left <= right) result.push_back(arr[left++]);  // Pick smallest
        }
        
        return result;
    }
};;


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
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends