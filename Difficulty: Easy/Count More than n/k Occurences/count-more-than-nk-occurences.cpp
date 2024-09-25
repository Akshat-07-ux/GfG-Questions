//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        // Step 1: Create a frequency map
        std::unordered_map<int, int> freqMap;
        
        // Step 2: Count frequencies of each element
        for (int i = 0; i < n; i++) {
            freqMap[arr[i]]++;
        }
        
        // Step 3: Determine the threshold
        int threshold = n / k;
        int count = 0;
        
        // Step 4: Count how many elements appear more than n/k times
        for (auto& entry : freqMap) {
            if (entry.second > threshold) {
                count++;
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends