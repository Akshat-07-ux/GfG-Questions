//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        long long int largest_prime = -1;

        // Step 1: Divide by 2 until N becomes odd
        while (N % 2 == 0) {
            largest_prime = 2;
            N /= 2;
        }

        // Step 2: Divide by odd numbers starting from 3
        for (int i = 3; i * i <= N; i += 2) {
            while (N % i == 0) {
                largest_prime = i;
                N /= i;
            }
        }

        // Step 3: If N is still greater than 2, then N is prime
        if (N > 2) {
            largest_prime = N;
        }

        return largest_prime;
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
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends