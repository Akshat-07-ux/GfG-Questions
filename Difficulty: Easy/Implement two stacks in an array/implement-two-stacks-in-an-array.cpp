//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class twoStacks {
    int *arr;
    int size;
    int top1, top2;

public:
    // Constructor to initialize the data structure
    twoStacks(int n = 100) {
        size = n;
        arr = new int[n];
        top1 = -1;             // Stack 1 starts from the left
        top2 = size;           // Stack 2 starts from the right
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        // Check for overflow
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        } else {
            // No space to push the element
            cout << "Stack Overflow" << endl;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        // Check for overflow
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = x;
        } else {
            // No space to push the element
            cout << "Stack Overflow" << endl;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if (top1 >= 0) {
            int x = arr[top1];
            top1--;
            return x;
        } else {
            // Stack 1 is empty
            return -1;
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if (top2 < size) {
            int x = arr[top2];
            top2++;
            return x;
        } else {
            // Stack 2 is empty
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--) {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1) {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            } else if (QueryType == 2) {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends