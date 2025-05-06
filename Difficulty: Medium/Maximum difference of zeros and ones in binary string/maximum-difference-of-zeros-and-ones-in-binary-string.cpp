//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
 public:
    int maxSubstring(string S) {
        int max_diff = -1;
        int current_sum = 0;

        for (char ch : S) {
            int val = (ch == '0') ? 1 : -1;
            current_sum += val;

            if (current_sum > max_diff) {
                max_diff = current_sum;
            }

            if (current_sum < 0) {
                current_sum = 0;
            }
        }

        return max_diff == -1 ? -1 : max_diff;
    }
};


//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends