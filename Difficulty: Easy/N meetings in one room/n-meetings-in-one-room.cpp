//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Vector to store meetings as pairs of (end, start)
        std::vector<std::pair<int, int>> meetings;
        
        // Fill the vector with the given start and end times
        for (int i = 0; i < n; ++i) {
            meetings.push_back({end[i], start[i]});
        }
        
        // Sort meetings by their end time
        std::sort(meetings.begin(), meetings.end());
        
        // Initialize variables to track the count of meetings
        // and the end time of the last selected meeting
        int count = 0;
        int last_end_time = -1;
        
        // Iterate through the sorted meetings
        for (const auto& meeting : meetings) {
            // If the start time of the current meeting is greater
            // than the end time of the last selected meeting
            if (meeting.second > last_end_time) {
                // Increment the count and update the end time
                count++;
                last_end_time = meeting.first;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends