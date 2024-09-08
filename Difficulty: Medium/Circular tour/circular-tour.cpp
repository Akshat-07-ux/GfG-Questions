//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
public:
    int tour(petrolPump p[], int n) {
        int total_petrol = 0;
        int total_distance = 0;
        int current_balance = 0;
        int start_index = 0;

        for (int i = 0; i < n; i++) {
            int petrol = p[i].petrol;
            int distance = p[i].distance;

            total_petrol += petrol;
            total_distance += distance;

            current_balance += (petrol - distance);

            // If current_balance is negative, cannot start from `start_index`
            if (current_balance < 0) {
                start_index = i + 1; // Next pump might be the start
                current_balance = 0; // Reset current balance
            }
        }

        // If total_petrol is less than total_distance, it's not possible to complete the tour
        if (total_petrol < total_distance) {
            return -1;
        }

        return start_index;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends