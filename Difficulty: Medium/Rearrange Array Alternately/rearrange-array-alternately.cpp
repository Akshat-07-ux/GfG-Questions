//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
 public:
    // Function to rearrange the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
        int max_idx = n - 1; // Index of the maximum element
        int min_idx = 0;      // Index of the minimum element
        long long max_element = arr[n - 1] + 1; // Maximum element + 1

        // Traverse the array and modify it in place
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                // Even index: Place maximum element
                arr[i] += (arr[max_idx] % max_element) * max_element;
                max_idx--;
            } else {
                // Odd index: Place minimum element
                arr[i] += (arr[min_idx] % max_element) * max_element;
                min_idx++;
            }
        }

        // Final transformation to get the actual values
        for (int i = 0; i < n; i++) {
            arr[i] /= max_element;
        }
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends