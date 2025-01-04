//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];

                if (sum == target) {
                    // Count duplicates for j and k
                    int left = 1, right = 1;

                    // Count the number of duplicate elements for arr[j]
                    while (j + left < k && arr[j] == arr[j + left]) left++;
                    // Count the number of duplicate elements for arr[k]
                    while (k - right > j && arr[k] == arr[k - right]) right++;

                    // If arr[j] and arr[k] are the same, we need to handle it differently
                    if (arr[j] == arr[k]) {
                        count += (k - j + 1) * (k - j) / 2;
                    } else {
                        count += left * right;
                    }

                    j += left;
                    k -= right;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return count;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends