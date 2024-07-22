//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    pair<long long, long long> getMinMax(vector<long long int> arr) {
        // Check if the array is empty
        if (arr.empty()) {
            return {0, 0}; // Return a default value, though in practice we assume the array is non-empty as per constraints
        }

        // Initialize min and max with the first element of the array
        long long minElem = arr[0];
        long long maxElem = arr[0];

        // Traverse the array to find the min and max elements
        for (long long elem : arr) {
            if (elem < minElem) {
                minElem = elem;
            }
            if (elem > maxElem) {
                maxElem = elem;
            }
        }

        // Return the result as a pair
        return {minElem, maxElem};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<long long int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        pair<long long, long long> pp = ob.getMinMax(arr);
        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends