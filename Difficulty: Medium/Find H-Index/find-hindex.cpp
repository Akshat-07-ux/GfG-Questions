//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        // Create a bucket array to count citations
        vector<int> bucket(n + 1, 0);

        // Fill the bucket array
        for (int c : citations) {
            if (c >= n) {
                bucket[n]++; // Count all citations >= n in the last bucket
            } else {
                bucket[c]++;
            }
        }

        // Calculate the H-index
        int hIndex = 0, papers = 0;
        for (int i = n; i >= 0; i--) {
            papers += bucket[i];
            if (papers >= i) {
                hIndex = i;
                break;
            }
        }

        return hIndex;
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends