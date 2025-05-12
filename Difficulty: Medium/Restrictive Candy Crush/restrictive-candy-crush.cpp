//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string Reduced_String(int k, string s) {
        if (k == 1) return "";  // All characters are removable

        stack<pair<char, int>> st;

        for (char ch : s) {
            if (!st.empty() && st.top().first == ch) {
                st.top().second += 1;

                if (st.top().second == k) {
                    st.pop();  // Remove the group
                }
            } else {
                st.push({ch, 1});
            }
        }

        // Build final reduced string
        string result;
        while (!st.empty()) {
            pair<char, int> top = st.top(); st.pop();
            char ch = top.first;
            int count = top.second;
            result.append(count, ch);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};



//{ Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    
cout << "~" << "\n";
}
    
	return 0;
}
// } Driver Code Ends