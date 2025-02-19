//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void sortBySetBitCount(int arr[], int n) {
        stable_sort(arr, arr + n, [](int a, int b) {
            return __builtin_popcount(a) > __builtin_popcount(b);
        });
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends