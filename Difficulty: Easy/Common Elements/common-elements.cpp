//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
 public:
    vector<int> commonElements(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<int> result;
        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                result.push_back(a[i]);
                i++;
                j++;
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }
        string str1;
        getline(cin, str1);

        stringstream ss1(str1);
        vector<int> b;
        int num1;
        while (ss1 >> num1) {
            b.push_back(num1);
        }
        Solution ob;
        vector<int> result;
        result = ob.commonElements(a, b);
        for (auto i : result) {
            cout << i << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends