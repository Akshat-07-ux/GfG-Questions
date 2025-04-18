//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPairs(vector<int>& arr1, vector<int>& arr2, int x) {
        int i = 0;
        int j = arr2.size() - 1;
        int count = 0;

        while (i < arr1.size() && j >= 0) {
            int sum = arr1[i] + arr2[j];
            if (sum == x) {
                count++;
                i++;
                j--;
            }
            else if (sum < x) {
                i++;
            }
            else {
                j--;
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string sums;
        getline(cin, sums);
        int sum = stoi(sums);
        vector<int> arr1, arr2;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            arr1.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        // Function calling
        int res = ob.countPairs(arr1, arr2, sum);

        cout << res << endl;
        cout << "~" << endl;

        // string tilde;
        // getline(cin, tilde);
    }

    return 0;
}

// } Driver Code Ends