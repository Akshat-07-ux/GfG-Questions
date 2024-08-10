//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution {
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // Sort jobs in descending order of profit
        sort(arr, arr + n, [](Job a, Job b) {
            return a.profit > b.profit;
        });

        // Find the maximum deadline
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        // Initialize a vector to keep track of time slots
        vector<bool> timeSlot(maxDeadline + 1, false);

        int jobsDone = 0;
        int maxProfit = 0;

        // Iterate through all jobs
        for (int i = 0; i < n; i++) {
            // Find a free time slot for this job
            for (int j = min(maxDeadline, arr[i].dead); j > 0; j--) {
                if (!timeSlot[j]) {
                    timeSlot[j] = true;
                    jobsDone++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }

        return {jobsDone, maxProfit};
    }
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends