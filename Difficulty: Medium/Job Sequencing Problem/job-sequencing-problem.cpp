//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> parent;

    // DSU find function to get the latest available slot
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;

        // Store jobs as pairs (profit, deadline)
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Sort jobs in descending order of profit
        sort(jobs.rbegin(), jobs.rend());

        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        parent.resize(maxDeadline + 1);

        // Initialize DSU parent array (self-parenting initially)
        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }

        int maxJobs = 0, totalProfit = 0;

        for (auto &job : jobs) {
            int profit = job.first, d = job.second;

            // Find the latest available slot using DSU
            int availableSlot = find(d);
            if (availableSlot > 0) {
                parent[availableSlot] = find(availableSlot - 1); // Merge to previous slot
                maxJobs++;
                totalProfit += profit;
            }
        }

        return {maxJobs, totalProfit};
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends