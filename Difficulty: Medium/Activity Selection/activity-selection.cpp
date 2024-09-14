//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum number of activities that can
    // be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n) {
        // Create a vector of pairs to store activities (start, end)
        vector<pair<int, int>> activities;
        for (int i = 0; i < n; ++i) {
            activities.push_back({end[i], start[i]});
        }
        
        // Sort activities based on their end time
        sort(activities.begin(), activities.end());
        
        // Initialize count of activities and the end time of the last selected activity
        int count = 0;
        int last_end_time = -1;
        
        // Iterate through sorted activities
        for (const auto& activity : activities) {
            // If the start time of the current activity is greater than the end time of the last selected activity
            if (activity.second > last_end_time) {
                // Select this activity
                ++count;
                // Update the end time of the last selected activity
                last_end_time = activity.first;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends