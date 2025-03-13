//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution{   
public:
    int isSumString(string S){
        int n = S.length();
        
        // Helper function to add two strings numerically
        auto sumOfStrings = [](const string& s1, const string& s2) -> string {
            string result;
            int i = s1.length() - 1;
            int j = s2.length() - 1;
            int carry = 0;
            
            while (i >= 0 || j >= 0 || carry > 0) {
                int digit1 = (i >= 0) ? (s1[i] - '0') : 0;
                int digit2 = (j >= 0) ? (s2[j] - '0') : 0;
                
                int sum = digit1 + digit2 + carry;
                carry = sum / 10;
                sum = sum % 10;
                
                result = to_string(sum) + result;
                
                i--;
                j--;
            }
            
            return result;
        };
        
        // Helper function to check if a substring matches the sum of two previous ones
        function<bool(int, int, int)> isSumStringUtil = [&](int start, int len1, int len2) -> bool {
            // Get the first two substrings
            string s1 = S.substr(start, len1);
            string s2 = S.substr(start + len1, len2);
            
            // Calculate their sum
            string sum = sumOfStrings(s1, s2);
            int sumLen = sum.length();
            
            // Check if we've reached the end of the string
            if (start + len1 + len2 + sumLen > n) {
                return false;
            }
            
            // Check if the next substring matches the calculated sum
            if (S.substr(start + len1 + len2, sumLen) != sum) {
                return false;
            }
            
            // If we've reached the end of the string, it's a valid sum-string
            if (start + len1 + len2 + sumLen == n) {
                return true;
            }
            
            // Recursively check for the next set of substrings
            return isSumStringUtil(start + len1, len2, sumLen);
        };
        
        // Try all possible lengths for first and second substrings
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n - i; j++) {
                // Skip if second substring has leading zeros (except for "0" itself)
                if (S[i] == '0' && j > 1) {
                    continue;
                }
                
                if (isSumStringUtil(0, i, j)) {
                    return 1;
                }
            }
        }
        
        return 0;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.isSumString(S) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 

// } Driver Code Ends