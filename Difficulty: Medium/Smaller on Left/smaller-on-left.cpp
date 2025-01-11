//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]) {
        vector<int> result(n);  // To store the result
        stack<int> st;  // Stack to keep track of previous elements

        for (int i = 0; i < n; ++i) {
            // Pop elements from the stack until we find a smaller element
            while (!st.empty() && st.top() >= a[i]) {
                st.pop();
            }

            // If stack is empty, no smaller element on the left
            if (st.empty()) {
                result[i] = -1;
            } else {
                result[i] = st.top();
            }

            // Push the current element onto the stack
            st.push(a[i]);
        }

        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends