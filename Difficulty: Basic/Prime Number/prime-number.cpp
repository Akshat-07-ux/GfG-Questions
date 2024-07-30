//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isPrime(int N) {
        if (N <= 1) return 0;
        if (N <= 3) return 1; // 2 and 3 are prime numbers
        
        // If N is divisible by 2 or 3, it is not prime
        if (N % 2 == 0 || N % 3 == 0) return 0;
        
        // Check from 5 to sqrt(N) with a step of 6
        for (int i = 5; i * i <= N; i += 6) {
            if (N % i == 0 || N % (i + 2) == 0) return 0;
        }
        
        return 1;
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends