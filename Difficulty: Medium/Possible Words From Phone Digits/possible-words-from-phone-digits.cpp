//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
public:
    // Map keypad numbers to corresponding characters
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void generateWords(int index, vector<int>& arr, string current, vector<string>& result) {
        // Base case: if index reaches the end of the array
        if (index == arr.size()) {
            result.push_back(current);
            return;
        }
        
        // Get the characters corresponding to the current number
        string letters = keypad[arr[index]];
        
        // Recursive step: iterate through each letter and recurse
        for (char letter : letters) {
            generateWords(index + 1, arr, current + letter, result);
        }
    }

    vector<string> possibleWords(vector<int>& arr) {
        vector<string> result;
        if (arr.empty()) return result;
        
        generateWords(0, arr, "", result);
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        vector<string> v = obj.possibleWords(a);

        Array::print(v);
        cout << "~" << endl;
    }
}

// } Driver Code Ends