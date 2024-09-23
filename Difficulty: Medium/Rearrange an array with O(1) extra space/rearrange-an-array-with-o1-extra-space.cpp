//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    public:
    // arr: input array
    // n: size of array
    // Function to rearrange an array so that arr[i] becomes arr[arr[i]] with O(1) extra space.
    void arrange(long long arr[], int n) {
        // Step 1: Encode both new and old values
        for (int i = 0; i < n; i++) {
            // Store both values in arr[i]: arr[i] = old_value + n * new_value
            arr[i] = arr[i] + (arr[arr[i]] % n) * n;
        }
        
        // Step 2: Decode the new values
        for (int i = 0; i < n; i++) {
            // Retrieve new value by dividing by n
            arr[i] = arr[i] / n;
        }
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin>>t;
    while(t--){
        
        int n;
        //size of array
        cin>>n;
        long long A[n];
        
        //adding elements to the array
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        Solution ob;
        //calling arrange() function
        ob.arrange(A, n);
        
        //printing the elements 
        for(int i=0;i<n;i++){
            cout << A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends