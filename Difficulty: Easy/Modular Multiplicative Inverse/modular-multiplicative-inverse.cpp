//{ Driver Code Starts
//Initial Template for C++

#include<iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    //Complete this function
    int modInverse(int a, int m) {
        // Iterating over possible values of x from 1 to m-1
        for (int x = 1; x < m; x++) {
            // Checking if this x is the modular inverse
            if ((a * x) % m == 1) {
                return x; // Smallest modular inverse found
            }
        }
        return -1; // No modular inverse exists
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	
	//taking testcases
	cin>>T;
	while(T--){
		int a,m;
		
		//taking input a and m
		cin>>a>>m;
		Solution ob;
		//calling function modInverse()
		cout << ob.modInverse(a, m)<<endl;
	
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends