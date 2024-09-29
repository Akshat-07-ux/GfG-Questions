//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
//User function template in C++


class Solution{
public:
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        // Step 1: Create a frequency map for A1
        unordered_map<int, int> freq;
        for (int num : A1) {
            freq[num]++;
        }
        
        // Step 2: Sort A1 based on A2
        vector<int> result;
        for (int num : A2) {
            if (freq.find(num) != freq.end()) {
                int count = freq[num];
                // Add the element to result count times
                for (int i = 0; i < count; i++) {
                    result.push_back(num);
                }
                // Remove the element from the frequency map after adding it
                freq.erase(num);
            }
        }
        
        // Step 3: Add remaining elements that were not in A2
        vector<int> remaining;
        for (auto& pair : freq) {
            int num = pair.first;
            int count = pair.second;
            // Add the remaining elements to a separate vector
            for (int i = 0; i < count; i++) {
                remaining.push_back(num);
            }
        }
        
        // Sort the remaining elements in ascending order
        sort(remaining.begin(), remaining.end());
        
        // Append the sorted remaining elements to the result
        result.insert(result.end(), remaining.begin(), remaining.end());
        
        return result;
    } 
};

//{ Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 

// } Driver Code Ends