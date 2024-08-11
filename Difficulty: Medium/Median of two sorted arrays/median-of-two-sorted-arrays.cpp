//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        int total = n * 2;
        int left = (total / 2) - 1;
        int right = total / 2;
        
        int count = 0;
        int i = 0, j = 0;
        int leftElement = 0, rightElement = 0;
        
        while (count <= right) {
            int num;
            if (i < n && j < n) {
                if (arr1[i] < arr2[j]) {
                    num = arr1[i++];
                } else {
                    num = arr2[j++];
                }
            } else if (i < n) {
                num = arr1[i++];
            } else {
                num = arr2[j++];
            }
            
            if (count == left) {
                leftElement = num;
            }
            if (count == right) {
                rightElement = num;
            }
            count++;
        }
        
        return leftElement + rightElement;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends