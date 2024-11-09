//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
 public:
    int findSingle(int n, int arr[]) {
        // Initialize result variable
        int result = 0;
        
        // XOR all elements in the array
        for(int i = 0; i < n; i++) {
            result ^= arr[i];
        }
        
        // Return the final result
        return result;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.findSingle(N, arr) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 
// } Driver Code Ends