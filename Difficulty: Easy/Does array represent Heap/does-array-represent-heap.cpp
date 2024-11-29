//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
   public:
    bool isMaxHeap(int arr[], int n) {
        // Traverse each parent node and check if it's greater than its children
        for (int i = 0; i <= (n - 2) / 2; i++) {
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;
            
            // Check the left child
            if (leftChild < n && arr[i] < arr[leftChild]) {
                return false;
            }
            
            // Check the right child
            if (rightChild < n && arr[i] < arr[rightChild]) {
                return false;
            }
        }
        return true; // It satisfies Max Heap properties
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends