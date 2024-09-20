//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
 {
    // Two heaps to store the elements
    priority_queue<int> maxHeap; // Max heap for the lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for the upper half
    
public:
    // Function to insert element into heaps
    void insertHeap(int &x) {
        // If maxHeap is empty or x is less than or equal to maxHeap's top, insert into maxHeap
        if (maxHeap.empty() || x <= maxHeap.top()) {
            maxHeap.push(x);
        } else {
            minHeap.push(x);
        }
        
        // Balance the heaps
        balanceHeaps();
    }
    
    // Function to balance the heaps
    void balanceHeaps() {
        // If maxHeap has more than one extra element compared to minHeap, move the top element from maxHeap to minHeap
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // If minHeap has more elements, move the top element from minHeap to maxHeap
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    // Function to return the median of the current stream
    double getMedian() {
        // If both heaps have the same size, the median is the average of the top elements
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        // Otherwise, the median is the top element of the maxHeap
        else {
            return maxHeap.top();
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends