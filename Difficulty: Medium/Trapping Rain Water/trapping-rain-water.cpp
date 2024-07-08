//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    long long trappingWater(int arr[], int n){
        if (n <= 2) return 0;
        
        vector<int> leftMax(n), rightMax(n);
        
        // Compute left maximum heights
        leftMax[0] = arr[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], arr[i]);
        }
        
        // Compute right maximum heights
        rightMax[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], arr[i]);
        }
        
        // Calculate trapped water
        long long totalWater = 0;
        for (int i = 0; i < n; i++) {
            int waterLevel = min(leftMax[i], rightMax[i]);
            if (waterLevel > arr[i]) {
                totalWater += waterLevel - arr[i];
            }
        }
        
        return totalWater;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends