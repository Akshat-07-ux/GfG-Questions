//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
public:
    vector<int> countDistinct(int A[], int n, int k) {
        vector<int> result; // To store the result of distinct counts for each window
        unordered_map<int, int> freq_map; // To store the frequency of elements in the current window
        int distinct_count = 0; // To track the number of distinct elements in the window

        // Process the first window of size k
        for (int i = 0; i < k; i++) {
            if (freq_map[A[i]] == 0) {
                distinct_count++; // New distinct element
            }
            freq_map[A[i]]++; // Increment the count of the current element
        }
        result.push_back(distinct_count); // Store the distinct count for the first window

        // Process the rest of the windows
        for (int i = k; i < n; i++) {
            // Remove the element that is sliding out of the window
            if (freq_map[A[i - k]] == 1) {
                distinct_count--; // It was the only occurrence of this element
            }
            freq_map[A[i - k]]--; // Decrease the frequency of the outgoing element

            // Add the new element coming into the window
            if (freq_map[A[i]] == 0) {
                distinct_count++; // New distinct element
            }
            freq_map[A[i]]++; // Increment the count of the new element

            // Store the distinct count for the current window
            result.push_back(distinct_count);
        }

        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends