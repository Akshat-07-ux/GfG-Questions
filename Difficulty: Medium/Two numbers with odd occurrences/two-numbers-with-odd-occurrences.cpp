//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        // Step 1: XOR all elements to find XOR of the two odd occurring numbers
        long long int xor_all = 0;
        for (long long int i = 0; i < N; i++) {
            xor_all ^= Arr[i];
        }

        // Step 2: Find the rightmost set bit in xor_all
        long long int rightmost_set_bit = xor_all & -xor_all;

        // Step 3: Divide numbers into two groups based on the rightmost set bit
        long long int num1 = 0, num2 = 0;
        for (long long int i = 0; i < N; i++) {
            if (Arr[i] & rightmost_set_bit) {
                num1 ^= Arr[i];
            } else {
                num2 ^= Arr[i];
            }
        }

        // Step 4: Sort the result in decreasing order
        if (num1 < num2) {
            swap(num1, num2);
        }

        return {num1, num2};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends