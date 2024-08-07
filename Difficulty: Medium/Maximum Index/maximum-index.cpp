//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // Function to find the maximum index difference.
    int maxIndexDiff(std::vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // Create and fill leftMin array
        std::vector<int> leftMin(n);
        leftMin[0] = arr[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = std::min(arr[i], leftMin[i - 1]);
        }

        // Create and fill rightMax array
        std::vector<int> rightMax(n);
        rightMax[n - 1] = arr[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            rightMax[j] = std::max(arr[j], rightMax[j + 1]);
        }

        // Traverse both arrays to find the maximum j - i
        int i = 0, j = 0, maxDiff = 0;
        while (j < n && i < n) {
            if (leftMin[i] <= rightMax[j]) {
                maxDiff = std::max(maxDiff, j - i);
                j++;
            } else {
                i++;
            }
        }

        return maxDiff;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;

        // calling maxIndexDiff() function
        cout << ob.maxIndexDiff(nums) << endl;
    }

    return 0;
}
// } Driver Code Ends