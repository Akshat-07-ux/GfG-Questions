//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    int closestToZero(int arr[], int n) {
        // Sort the array
        sort(arr, arr + n);

        int left = 0;
        int right = n - 1;
        int closestSum = INT_MAX;

        // Using two-pointer technique
        while (left < right) {
            int sum = arr[left] + arr[right];

            // Check if this sum is closer to zero
            if (abs(sum) < abs(closestSum)) {
                closestSum = sum;
            } else if (abs(sum) == abs(closestSum)) {
                // If two sums are equally close, take the maximum sum
                closestSum = max(closestSum, sum);
            }

            // Move the pointers based on the sum
            if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }

        return closestSum;
    }
};


//{ Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends