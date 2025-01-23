//{ Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to calculate the sum of all numbers present in a string.
    int findSum(string& s) {
        int sum = 0;       // To store the total sum
        int number = 0;    // To extract individual numbers
        
        for (char c : s) {
            if (isdigit(c)) {
                // If the character is a digit, build the number
                number = number * 10 + (c - '0');
            } else {
                // If the character is not a digit, add the current number to the sum
                sum += number;
                number = 0; // Reset the number
            }
        }
        
        // Add the last number (if any) to the sum
        sum += number;
        
        return sum;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    // input alphanumeric string
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution obj;
        cout << obj.findSum(str);
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends