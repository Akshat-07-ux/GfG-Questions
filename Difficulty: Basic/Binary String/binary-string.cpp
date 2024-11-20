//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
 public:
    // Function to count the number of substrings that start and end with 1.
    long binarySubstring(int n, string a) {
        // Step 1: Count the number of '1's in the string
        long count = 0;
        for (char ch : a) {
            if (ch == '1') {
                count++;
            }
        }

        // Step 2: Calculate the number of substrings
        return (count * (count - 1)) / 2;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n,count;
    string a;
    cin>>t;
    while(t--)
    {
        count = 0;
        cin >> n;
        cin >> a;
        Solution obj;
        cout << obj.binarySubstring(n, a) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends