//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Create a min-heap (priority queue)
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        
        // Push all the elements of the array into the min-heap
        for (long long length : arr) {
            minHeap.push(length);
        }
        
        // Initialize the total cost
        long long totalCost = 0;
        
        // While there are more than one rope to connect
        while (minHeap.size() > 1) {
            // Pop the two smallest elements
            long long first = minHeap.top();
            minHeap.pop();
            long long second = minHeap.top();
            minHeap.pop();
            
            // The cost to connect these two ropes
            long long cost = first + second;
            
            // Add this cost to the total cost
            totalCost += cost;
            
            // Push the new rope back into the min-heap
            minHeap.push(cost);
        }
        
        // Return the total cost to connect all ropes
        return totalCost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends