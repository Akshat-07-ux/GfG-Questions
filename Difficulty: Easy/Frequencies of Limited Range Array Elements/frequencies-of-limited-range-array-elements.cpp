//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
class Solution{
    public:
    // Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr, int N, int P) { 
        // Step 1: Create a frequency array to store the counts of each element
        vector<int> freq(N + 1, 0); // Initialize with 0s, freq[0] will be unused
        
        // Step 2: Count frequencies of elements within the range 1 to N
        for (int num : arr) {
            if (num >= 1 && num <= N) {
                freq[num]++;
            }
        }
        
        // Step 3: Update the original array with the frequencies
        for (int i = 0; i < N; ++i) {
            arr[i] = freq[i + 1];
        }
    }
};


//{ Driver Code Starts.

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int N, P;
	    //size of array
	    cin >> N; 
	    
	    vector<int> arr(N);
	    
	    //adding elements to the vector
	    for(int i = 0; i < N ; i++){
	        cin >> arr[i]; 
	    }
        cin >> P;
        Solution ob;
        //calling frequncycount() function
		ob.frequencyCount(arr, N, P); 
		
		//printing array elements
	    for (int i = 0; i < N ; i++) 
			cout << arr[i] << " ";
	    cout << endl;
	}	
	return 0; 
}





// } Driver Code Ends