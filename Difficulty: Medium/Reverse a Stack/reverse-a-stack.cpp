//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    // Helper function to insert element at the bottom of the stack
    void insertAtBottom(stack<int> &St, int ele) {
        if (St.empty()) {
            // Base case: if the stack is empty, push the element
            St.push(ele);
        } else {
            // Recursively pop all elements to reach the bottom
            int top = St.top();
            St.pop();
            
            // Recursive call to insert element at the bottom
            insertAtBottom(St, ele);
            
            // Push the popped element back onto the stack
            St.push(top);
        }
    }
    
    // Function to reverse the stack
    void Reverse(stack<int> &St) {
        if (!St.empty()) {
            // Pop the top element
            int top = St.top();
            St.pop();
            
            // Recursively reverse the remaining stack
            Reverse(St);
            
            // Insert the popped element at the bottom
            insertAtBottom(St, top);
        }
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends