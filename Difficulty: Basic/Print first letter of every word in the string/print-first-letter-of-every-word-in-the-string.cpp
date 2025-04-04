//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++
class Solution{
public:	
	string firstAlphabet(string S) {
	    string result;
	    result += S[0]; // First word's first letter

	    for (int i = 1; i < S.size(); i++) {
	        if (S[i] == ' ' && i + 1 < S.size()) {
	            result += S[i + 1]; // Add first letter of next word
	        }
	    }
	    
	    return result;
	}
};



//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	
        Solution ob;
   		cout << ob.firstAlphabet(s) << "\n";
   	
cout << "~" << "\n";
}

    return 0;
} 

// } Driver Code Ends