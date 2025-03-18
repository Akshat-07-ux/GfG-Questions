//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for c++
class Solution {
  public:
    string removeChars(string string1, string string2) {
        unordered_set<char> toRemove(string2.begin(), string2.end());
        string result;
        
        for (char ch : string1) {
            if (toRemove.find(ch) == toRemove.end()) {
                result += ch; // Append only if not present in string2
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends