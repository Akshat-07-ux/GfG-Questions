//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  
public:
    // Function to check if two arrays are equal or not.
    bool check(vector<int>& arr1, vector<int>& arr2) {
        // Check if the sizes are different
        if (arr1.size() != arr2.size()) {
            return false;
        }
        
        // Create a map to store the frequency of elements in arr1
        unordered_map<int, int> freq;
        
        // Count the frequency of elements in arr1
        for (int num : arr1) {
            freq[num]++;
        }
        
        // Check if the elements in arr2 match the frequency in arr1
        for (int num : arr2) {
            if (freq.find(num) == freq.end() || freq[num] == 0) {
                return false;
            }
            freq[num]--;
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr1, arr2;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the first array elements
        stringstream ss1(input1);
        int number;
        while (ss1 >> number) {
            arr1.push_back(number);
        }

        getline(cin, input2); // Read the entire line for the second array elements
        stringstream ss2(input2);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        cout << (ob.check(arr1, arr2) ? "true" : "false") << "\n";
    }
    return 0;
}
// } Driver Code Ends