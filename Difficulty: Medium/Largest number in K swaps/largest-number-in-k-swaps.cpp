//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
private:
    // Helper function to perform the recursive swaps
    void findMaximumNumHelper(string& str, int k, string& max_num, int index) {
        // Base case: if no more swaps left or we've reached the end of the string
        if (k == 0 || index == str.length() - 1) {
            max_num = max(max_num, str);
            return;
        }
        
        // Find the maximum digit in the remaining part of the string
        char max_digit = str[index];
        for (int i = index + 1; i < str.length(); i++) {
            if (str[i] > max_digit) {
                max_digit = str[i];
            }
        }
        
        // If the current digit is already the maximum, move to the next index
        if (max_digit == str[index]) {
            findMaximumNumHelper(str, k, max_num, index + 1);
            return;
        }
        
        // Try swapping with each occurrence of the maximum digit
        for (int i = str.length() - 1; i > index; i--) {
            if (str[i] == max_digit) {
                swap(str[index], str[i]);
                findMaximumNumHelper(str, k - 1, max_num, index + 1);
                swap(str[index], str[i]); // backtrack
            }
        }
    }

public:
    // Function to find the largest number after k swaps
    string findMaximumNum(string str, int k)
    {
        string max_num = str;
        findMaximumNumHelper(str, k, max_num, 0);
        return max_num;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends