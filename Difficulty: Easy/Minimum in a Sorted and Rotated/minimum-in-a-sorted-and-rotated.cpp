//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int findMin(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;
        
        while (start < end) {
            int mid = start + (end - start) / 2;
            
            // If the mid element is greater than the end element,
            // the minimum is in the right half
            if (arr[mid] > arr[end]) {
                start = mid + 1;
            } 
            // Otherwise, the minimum is in the left half, including mid
            else {
                end = mid;
            }
        }
        
        // After the loop, start == end, pointing to the minimum element
        return arr[start];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
    }
    return 0;
}

// } Driver Code Ends