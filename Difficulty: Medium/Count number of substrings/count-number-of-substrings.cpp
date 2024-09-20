//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
 public:
    long long int substrCount (string s, int k) {
        return atMostK(s, k) - atMostK(s, k-1);
    }
    
  private:
    long long int atMostK(string &s, int k) {
        vector<int> char_count(26, 0);
        long long int count = 0;
        int distinct = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            if (char_count[s[right] - 'a'] == 0) {
                distinct++;
            }
            char_count[s[right] - 'a']++;
            
            while (distinct > k) {
                char_count[s[left] - 'a']--;
                if (char_count[s[left] - 'a'] == 0) {
                    distinct--;
                }
                left++;
            }
            
            count += right - left + 1;
        }
        
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends