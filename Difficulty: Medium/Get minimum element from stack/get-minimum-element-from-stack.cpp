//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
 std::stack<int> s; // Main stack
    std::stack<int> minStack; // Stack to keep track of minimum elements
    
public:
    // Returns the minimum element from the stack
    int getMin() {
        if (minStack.empty()) {
            return -1; // Return -1 if the stack is empty
        }
        return minStack.top();
    }
    
    // Returns popped element from the stack
    int pop() {
        if (s.empty()) {
            return -1; // Return -1 if the stack is empty
        }
        
        int topElement = s.top();
        s.pop();
        
        if (topElement == minStack.top()) {
            minStack.pop();
        }
        
        return topElement;
    }
    
    // Push element x into the stack
    void push(int x) {
        s.push(x);
        
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends