//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int left = 0, right = a.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Compare mid with its next element
            if (a[mid] < a[mid + 1]) {
                // Peak lies on the right side
                left = mid + 1;
            } else {
                // Peak lies on the left side or mid is the peak
                right = mid;
            }
        }

        // At the end of the loop, left == right and points to the peak element
        return a[left];
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    
cout << "~" << "\n";
}
	return 0;
}


// } Driver Code Ends