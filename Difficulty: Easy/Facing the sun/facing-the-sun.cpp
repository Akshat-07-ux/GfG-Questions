//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Returns count of buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        int count = 1; // The first building always sees the sunrise
        int max_height = height[0]; // Initialize the max height with the first building's height
        
        // Traverse the array from the second building onwards
        for (int i = 1; i < height.size(); i++) {
            // If the current building is taller than all previous ones
            if (height[i] > max_height) {
                count++; // It can see the sunrise
                max_height = height[i]; // Update the max height
            }
        }
        
        return count; // Return the total count of buildings that can see the sunrise
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> height;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            height.push_back(number);
        }
        Solution ob;
        int ans = ob.countBuildings(height);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends