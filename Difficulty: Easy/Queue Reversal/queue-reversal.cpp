//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{
 public:
    // Function to reverse the queue
    queue<int> rev(queue<int> q)
    {
        stack<int> s;
        
        // Step 1: Push all elements of the queue into a stack
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }
        
        // Step 2: Pop all elements from the stack back into the queue
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
        
        return q;
    }
};

//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends