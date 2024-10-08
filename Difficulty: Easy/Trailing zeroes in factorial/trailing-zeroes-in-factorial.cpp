//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int trailingZeroes(int N) {
        int count = 0;
        
        // Keep dividing N by powers of 5 and update the count
        for (int i = 5; N / i > 0; i *= 5) {
            count += N / i;
        }
        
        return count;
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
        cin >> N;
        Solution ob;
        int ans  = ob.trailingZeroes(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends