//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
public:
    int chocolates(int n, vector<int> &arr) {
        int left = 0, right = n - 1;
        
        // Ishaan eats the chocolates greedily
        while (left < right) {
            if (arr[left] > arr[right]) {
                left++;  // Ishaan eats the leftmost chocolate
            } else {
                right--; // Ishaan eats the rightmost chocolate
            }
        }
        
        // The last remaining chocolate is eaten by Ishaan's sister
        return arr[left];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.chocolates(n, arr);
        
        cout<<res<<endl;
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends