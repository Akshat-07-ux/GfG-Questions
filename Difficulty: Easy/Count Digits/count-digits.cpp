//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N) {
        int originalNumber = N;
        int count = 0;

        while (N > 0) {
            int digit = N % 10;
            if (digit != 0 && originalNumber % digit == 0) {
                count++;
            }
            N /= 10;
        }

        return count;
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
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends