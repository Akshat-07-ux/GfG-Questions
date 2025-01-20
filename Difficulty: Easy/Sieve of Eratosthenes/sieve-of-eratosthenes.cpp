//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N) {
        // Initialize a boolean array to mark primes
        vector<bool> isPrime(N + 1, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not primes

        // Perform the Sieve of Eratosthenes
        for (int i = 2; i * i <= N; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= N; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Collect all prime numbers
        vector<int> primes;
        for (int i = 2; i <= N; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends