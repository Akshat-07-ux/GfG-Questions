//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
#include <unordered_map>
#include <math.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    // Function to return list containing all the pairs having both
    // negative and positive values of a number in the array.
    vector<int> findPairs(int arr[], int n) {
        unordered_set<int> hashSet;  // Store elements for quick lookup
        vector<int> result;

        // Traverse the array
        for (int i = 0; i < n; i++) {
            int num = arr[i];

            // Check if the opposite number exists in the set
            if (hashSet.find(-num) != hashSet.end()) {
                result.push_back(-abs(num));  // Store negative first
                result.push_back(abs(num));   // Then positive
            }

            // Insert current number into set
            hashSet.insert(num);
        }

        // If no pairs exist, return {0}
        if (result.empty()) return {0};
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        vector <int> res = obj.findPairs(arr, n);
    	if(res.size()!=0)
    	{
    		for (int i : res) 
            	cout << i << " ";
        	cout << endl;	
    	}
    	else
    		cout<<0<<endl;
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends