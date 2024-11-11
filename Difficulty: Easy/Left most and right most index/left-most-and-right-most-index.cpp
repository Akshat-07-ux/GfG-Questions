//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
   public:
    // Function to find the first occurrence of X
    long long findFirst(const vector<long long>& v, long long x) {
        long long low = 0, high = v.size() - 1;
        long long firstIndex = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (v[mid] == x) {
                firstIndex = mid;
                high = mid - 1; // continue searching on the left side
            } else if (v[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return firstIndex;
    }
    
    // Function to find the last occurrence of X
    long long findLast(const vector<long long>& v, long long x) {
        long long low = 0, high = v.size() - 1;
        long long lastIndex = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (v[mid] == x) {
                lastIndex = mid;
                low = mid + 1; // continue searching on the right side
            } else if (v[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return lastIndex;
    }
    
    // Function to find both the first and last occurrences of X
    pair<long long, long long> indexes(vector<long long> v, long long x) {
        long long first = findFirst(v, x);
        if (first == -1) {
            return {-1, -1}; // If X is not found
        }
        long long last = findLast(v, x);
        return {first, last};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends