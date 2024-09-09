//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    // Function to check if a given number is a palindrome
    bool isPalindrome(int num) {
        string str = to_string(num);
        int left = 0;
        int right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    // Function to check if all elements in the array are palindromes
    bool PalinArray(vector<int> &arr) {
        for (int num : arr) {
            if (!isPalindrome(num)) {
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << (ob.PalinArray(arr) ? "true" : "false") << endl;
    }

    return 0;
}

// } Driver Code Ends