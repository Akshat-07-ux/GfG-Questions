//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
 public:
    vector<int> bracketNumbers(string str) {
        vector<int> result;
        int count = 0;
        vector<int> stack;

        for (char ch : str) {
            if (ch == '(') {
                count++;
                stack.push_back(count);
                result.push_back(count);
            } else if (ch == ')') {
                result.push_back(stack.back());
                stack.pop_back();
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n~\n";
    }

    return 0;
}
// } Driver Code Ends