//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
 public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string S) {
        stack<int> stk;
        
        for (char ch : S) {
            // If the character is a digit, push it onto the stack as an integer
            if (isdigit(ch)) {
                stk.push(ch - '0');  // Convert char to int
            } else {
                // Pop the top two elements for the operation
                int operand2 = stk.top(); stk.pop();
                int operand1 = stk.top(); stk.pop();
                
                // Apply the operation and push the result back onto the stack
                switch (ch) {
                    case '+': stk.push(operand1 + operand2); break;
                    case '-': stk.push(operand1 - operand2); break;
                    case '*': stk.push(operand1 * operand2); break;
                    case '/': stk.push(operand1 / operand2); break;
                }
            }
        }
        
        // The final result will be the only element left in the stack
        return stk.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends