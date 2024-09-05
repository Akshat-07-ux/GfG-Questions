//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
 public:
    //Function to calculate the span of stock’s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        // Result vector to store the span of each day.
        vector<int> span(n);
        
        // Stack to store indices of the price array.
        stack<int> s;
        
        // Iterate over all days.
        for (int i = 0; i < n; i++) {
            // Pop elements from the stack while the stack is not empty and the
            // current price is greater than or equal to the price at the top of the stack.
            while (!s.empty() && price[i] >= price[s.top()]) {
                s.pop();
            }
            
            // If stack becomes empty, it means the current price is greater than all previous prices.
            // So the span is i+1.
            if (s.empty()) {
                span[i] = i + 1;
            }
            else {
                // Otherwise, the span is the difference between current index and the last higher price's index.
                span[i] = i - s.top();
            }
            
            // Push the current index to the stack.
            s.push(i);
        }
        
        return span;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends