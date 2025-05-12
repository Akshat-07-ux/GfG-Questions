//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
   public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; ++i) {
            freeRooms.push(i);
        }

        typedef pair<long long, int> PII;
        priority_queue<PII, vector<PII>, greater<PII>> busyRooms;

        vector<int> meetingCount(n, 0);

        for (const auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];

            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top(); freeRooms.pop();
                busyRooms.push({end, room});
                meetingCount[room]++;
            } else {
                pair<long long, int> top = busyRooms.top(); busyRooms.pop();
                long long availableTime = top.first;
                int room = top.second;
                long long duration = end - start;
                busyRooms.push({availableTime + duration, room});
                meetingCount[room]++;
            }
        }

        int maxMeetings = 0, resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (meetingCount[i] > maxMeetings) {
                maxMeetings = meetingCount[i];
                resultRoom = i;
            }
        }
        return resultRoom;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends