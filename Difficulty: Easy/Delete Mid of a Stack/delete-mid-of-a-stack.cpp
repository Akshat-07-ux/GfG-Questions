//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Helper function to remove the middle element recursively
    void deleteMiddleHelper(stack<int>& s, int current, int mid) {
        // Base case: if the current index is the middle, remove it
        if (current == mid) {
            s.pop();
            return;
        }

        // Store the current top element and pop it
        int topElement = s.top();
        s.pop();

        // Recursive call to reach the middle element
        deleteMiddleHelper(s, current + 1, mid);

        // Push the stored elements back except the middle one
        s.push(topElement);
    }

    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s, int sizeOfStack) {
        // Calculate the middle index (0-based indexing)
        int mid = sizeOfStack / 2;

        // Call the helper function to delete the middle element
        deleteMiddleHelper(s, 0, mid);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++) {
            int x;
            cin >> x;
            myStack.push(x);
        }

        Solution ob;
        ob.deleteMid(myStack, myStack.size());
        while (!myStack.empty()) {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends