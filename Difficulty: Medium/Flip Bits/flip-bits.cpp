//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
  public:
    int maxOnes(int a[], int n)
    {
        int originalOnes = 0; // Count of original 1's in the array
        int maxDiff = 0;      // Maximum difference obtained by flipping
        int currentDiff = 0;  // Current difference while iterating

        for (int i = 0; i < n; ++i) {
            // If the element is 1, we treat it as -1 to minimize its contribution in the flipped subarray
            // If the element is 0, we treat it as +1 to maximize its contribution
            int value = (a[i] == 0) ? 1 : -1;

            // Update current difference
            currentDiff += value;

            // Update maxDiff to get the maximum possible gain from flipping
            maxDiff = std::max(maxDiff, currentDiff);

            // If currentDiff becomes negative, reset it (start a new subarray)
            if (currentDiff < 0) {
                currentDiff = 0;
            }

            // Count the number of original 1's
            if (a[i] == 1) {
                originalOnes++;
            }
        }

        // To handle the case where no flipping is done, maxDiff could be 0
        // Add the original number of 1's to the maximum gain obtained from flipping
        return originalOnes + maxDiff;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends