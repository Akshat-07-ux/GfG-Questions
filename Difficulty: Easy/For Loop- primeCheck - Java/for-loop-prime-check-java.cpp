//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
 public:
    string isPrime(int n) {
        // 1 is not prime
        if (n <= 1) {
            return "No";
        }

        // Check for factors up to the square root of n
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                return "No";  // Not a prime number
            }
        }

        return "Yes";  // Prime number
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        Solution obj;
        string res = obj.isPrime(n);
        
        cout<<res<<"\n";
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends