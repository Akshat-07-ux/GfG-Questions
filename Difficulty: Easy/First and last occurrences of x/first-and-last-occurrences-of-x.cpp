//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findFirstOccurrence(vector<int>& arr, int x) {
        int left = 0, right = arr.size() - 1, first = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x) {
                first = mid;   // Found x, update first
                right = mid - 1; // Move left to find first occurrence
            } else if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return first;
    }

    int findLastOccurrence(vector<int>& arr, int x) {
        int left = 0, right = arr.size() - 1, last = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x) {
                last = mid;   // Found x, update last
                left = mid + 1; // Move right to find last occurrence
            } else if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return last;
    }

    vector<int> firstAndLast(int x, vector<int>& arr) {
        int first = findFirstOccurrence(arr, x);
        if (first == -1) return {-1}; // x not found
        int last = findLastOccurrence(arr, x);
        return {first, last};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> ans = obj.firstAndLast(x, arr);
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends