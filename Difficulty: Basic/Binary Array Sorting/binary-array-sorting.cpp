//{ Driver Code Starts
// A Sample C++ program for beginners with Competitive Programming

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    
    // A[]: input array
    // N: size of the input array
    // Function to sort the binary array.
    void binSort(int A[], int N)
    {
        int countZero = 0;

        // Counting number of 0's in the array
        for (int i = 0; i < N; i++) {
            if (A[i] == 0) {
                countZero++;
            }
        }

        // Fill first 'countZero' elements with 0
        for (int i = 0; i < countZero; i++) {
            A[i] = 0;
        }

        // Fill the remaining elements with 1
        for (int i = countZero; i < N; i++) {
            A[i] = 1;
        }
    }
};

//{ Driver Code Starts.
int main() {
	int T;
	cin>>T;
	// Input the number of testcases
	while(T--)
	{
	    int N;
	    cin>>N; //Input size of array N
	    int A[N]; 
	    
	    for(int i = 0; i  < N; i++)
	      cin>>A[i];
	      
	    Solution obj;
	    obj.binSort(A,N);
	    
	    for(int x:A)
	    cout<<x<<" ";
	      
	    cout<<endl;
	}
	return 0;
}




// } Driver Code Ends