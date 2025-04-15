//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++
class Solution{
public:
    void generate(int n, int ones, int zeros, string str, vector<string>& res) {
        if (str.length() == n) {
            res.push_back(str);
            return;
        }
        // Always can add '1'
        generate(n, ones + 1, zeros, str + '1', res);

        // Add '0' only if ones > zeros
        if (ones > zeros) {
            generate(n, ones, zeros + 1, str + '0', res);
        }
    }

    vector<string> NBitBinary(int n) {
        vector<string> res;
        generate(n, 0, 0, "", res);
        // Since we build from scratch, they’re in increasing order
        sort(res.rbegin(), res.rend()); // reverse sort
        return res;
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
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends