//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    // Function to check if a string is a palindrome
    bool isPalindrome(const string& str) {
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left++] != str[right--]) {
                return false;
            }
        }
        return true;
    }

    // Function to check if a palindrome pair exists
    bool palindromepair(int N, string arr[]) {
        unordered_map<string, int> reverseMap;

        // Store the reversed strings in a hash map
        for (int i = 0; i < N; i++) {
            string reversedStr = arr[i];
            reverse(reversedStr.begin(), reversedStr.end());
            reverseMap[reversedStr] = i;
        }

        // Check for palindrome pairs
        for (int i = 0; i < N; i++) {
            string str = arr[i];
            int len = str.size();

            for (int j = 0; j <= len; j++) {
                string prefix = str.substr(0, j);
                string suffix = str.substr(j);

                // Check if prefix is a palindrome and the reverse of suffix exists
                if (isPalindrome(prefix) && reverseMap.count(suffix) && reverseMap[suffix] != i) {
                    return true;
                }

                // Check if suffix is a palindrome and the reverse of prefix exists
                if (isPalindrome(suffix) && reverseMap.count(prefix) && reverseMap[prefix] != i && j != len) {
                    return true;
                }
            }
        }

        return false;
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
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 

// } Driver Code Ends