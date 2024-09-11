//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find all pairs with the given sum.
    vector<pair<int, int>> allPairs(int x, vector<int> &arr1, vector<int> &arr2) {
        vector<pair<int, int>> result;
        unordered_set<int> set_arr2(arr2.begin(), arr2.end());

        // Traverse through arr1 and find the complementary values in arr2.
        for (int num1 : arr1) {
            int complement = x - num1;
            if (set_arr2.find(complement) != set_arr2.end()) {
                result.push_back({num1, complement});
            }
        }

        // Sort the result pairs based on the first element, and then by the second.
        sort(result.begin(), result.end());

        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr1;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2); // Read the entire line for the array elements
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }

        Solution ob;
        vector<pair<int, int>> vp = ob.allPairs(x, arr1, arr2);
        int sz = vp.size();
        if (sz == 0)
            cout << -1 << endl;
        else {
            for (int i = 0; i < sz; i++) {
                if (i == 0)
                    cout << vp[i].first << " " << vp[i].second;
                else
                    cout << ", " << vp[i].first << " " << vp[i].second;
            }
            cout << endl;
        }
    }

    return 0;
}
// } Driver Code Ends