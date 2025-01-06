//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[],int n);

void _getMinAtPop(stack<int>s);

// } Driver Code Ends
//User function Template for C++

stack<int> _push(int arr[], int n) {
    stack<int> s;
    stack<int> minStack;

    for (int i = 0; i < n; ++i) {
        s.push(arr[i]);

        // Update minStack with the minimum value
        if (minStack.empty() || arr[i] <= minStack.top()) {
            minStack.push(arr[i]);
        } else {
            minStack.push(minStack.top());
        }
    }

    return minStack;
}

// Function to print minimum value in stack each time while popping
void _getMinAtPop(stack<int> minStack) {
    while (!minStack.empty()) {
        cout << minStack.top() << " ";
        minStack.pop();
    }
}

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    
	    cout<<endl;
	    
	}
	return 0;
}


// } Driver Code Ends