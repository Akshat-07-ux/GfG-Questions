//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // Helper function to perform DFS to check connectivity
    void dfs(char node, unordered_map<char, vector<char>> &graph, unordered_set<char> &visited) {
        visited.insert(node);
        for (char neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, graph, visited);
            }
        }
    }

    // Function to check if the given strings can form a circle
    int isCircle(vector<string> &arr) {
        // Edge case: if there is only one string, it must form a circle with itself
        if (arr.size() == 1) {
            return arr[0].front() == arr[0].back();
        }

        // Step 1: Initialize in-degree and out-degree arrays and graph
        unordered_map<char, int> in_degree, out_degree;
        unordered_map<char, vector<char>> graph;

        // Step 2: Populate in-degree, out-degree and the graph
        for (const string &str : arr) {
            char start = str.front();
            char end = str.back();

            out_degree[start]++;
            in_degree[end]++;
            graph[start].push_back(end);
        }

        // Step 3: Check if in-degree and out-degree of every vertex matches
        for (const auto &entry : in_degree) {
            if (in_degree[entry.first] != out_degree[entry.first]) {
                return 0;
            }
        }

        // Step 4: Check if all vertices with non-zero degree are in the same connected component
        unordered_set<char> visited;
        dfs(arr[0].front(), graph, visited);

        for (const auto &entry : out_degree) {
            if (entry.second > 0 && visited.find(entry.first) == visited.end()) {
                return 0;
            }
        }

        // Step 5: If all checks pass, the strings can form a circle
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends