//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool find4Numbers(int A[], int n, int X);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, x;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin>>x;
        cout << find4Numbers(a, n, x) << endl;

    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends


//User function Template for C++

bool find4Numbers(int A[], int n, int X)  
{
    // Sort the array
    std::sort(A, A + n);

    // Fix the first two elements one by one
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            // Initialize two pointers
            int left = j + 1;
            int right = n - 1;

            // Check for the other two elements
            while (left < right) {
                int currentSum = A[i] + A[j] + A[left] + A[right];
                
                if (currentSum == X) {
                    // Found the combination
                    return true;
                }
                else if (currentSum < X) {
                    // Increase the left pointer
                    left++;
                }
                else {
                    // Decrease the right pointer
                    right--;
                }
            }
        }
    }
    // No such combination found
    return false;
}