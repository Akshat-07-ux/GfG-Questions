//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    // Function to fill the array elements into a hash table 
    // using Quadratic Probing to handle collisions.
    void QuadraticProbing(vector<int>& hash, int hashSize, int arr[], int N) {
        for (int i = 0; i < N; i++) {
            int key = arr[i];
            int index = key % hashSize;

            // Check for duplicates while probing
            bool alreadyPresent = false;
            for (int j = 0; j < hashSize; j++) {
                int newIndex = (index + j * j) % hashSize;
                if (hash[newIndex] == key) {
                    alreadyPresent = true;
                    break;
                }
                if (hash[newIndex] == -1) break; // Stop early if empty
            }

            if (alreadyPresent) continue; // Don't insert duplicates

            // If no duplicate found, do probing and insert
            for (int j = 0; j < hashSize; j++) {
                int newIndex = (index + j * j) % hashSize;
                if (hash[newIndex] == -1) {
                    hash[newIndex] = key;
                    break;
                }
            }
        }
    }
};


//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    
	    
	    int  N;
	    cin>>N;
	    int arr[N];
	    
	    for(int i=0;i<N;i++)
	    cin>>arr[i];
	    
	    vector<int> hash (hashSize,-1);
	    Solution obj;
	    obj.QuadraticProbing (hash, hashSize, arr, N);
	    
	    for(int i = 0;i < hashSize; i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	
cout << "~" << "\n";
}
	return 0;
}



// } Driver Code Ends