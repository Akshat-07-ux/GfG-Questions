//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    
cout << "~" << "\n";
}
}
// } Driver Code Ends


// Function to search for K in the rotated sorted array
int Search(vector<int> vec, int K) {
    int left = 0, right = vec.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If K is found at mid, return the index
        if (vec[mid] == K) return mid;

        // Check which half is sorted
        if (vec[left] <= vec[mid]) {  // Left half is sorted
            if (vec[left] <= K && K < vec[mid]) 
                right = mid - 1;  // Search in left half
            else 
                left = mid + 1;   // Search in right half
        } else {  // Right half is sorted
            if (vec[mid] < K && K <= vec[right]) 
                left = mid + 1;  // Search in right half
            else 
                right = mid - 1; // Search in left half
        }
    }

    return -1;  // K not found
}