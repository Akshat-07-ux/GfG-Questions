//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // Use unordered sets to store unique elements from both arrays
        unordered_set<int> setA(a.begin(), a.end());
        unordered_set<int> intersection;

        // Iterate through array b and check for common elements in setA
        for (int num : b) {
            if (setA.find(num) != setA.end()) {
                intersection.insert(num);
            }
        }

        // Convert the set to a vector for the result
        return vector<int>(intersection.begin(), intersection.end());
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        vector<int> res = ob.intersectionWithDuplicates(arr1, arr2);
        sort(res.begin(), res.end());

        if (res.size() == 0) {
            cout << "[]" << endl;
        } else {
            for (auto it : res)
                cout << it << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends