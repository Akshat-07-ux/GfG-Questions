//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        // Traversing the string
        for (char ch : x)
        {
            // If the current character is an opening bracket, push it onto the stack
            if (ch == '(' || ch == '{' || ch == '[')
            {
                s.push(ch);
            }
            else
            {
                // If stack is empty and a closing bracket appears, it is not balanced
                if (s.empty())
                    return false;
                
                char top = s.top();
                s.pop();
                
                // Check if the popped opening bracket matches the current closing bracket
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
                {
                    return false;
                }
            }
        }
        // If the stack is empty, it means all opening brackets have been matched
        return s.empty();
    }
};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends