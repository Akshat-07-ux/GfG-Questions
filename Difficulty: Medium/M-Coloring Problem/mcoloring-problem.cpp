//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Helper function to check if the current color assignment is valid for vertex v.
    bool isSafe(int v, bool graph[101][101], int color[], int c, int n) {
        // Check adjacent vertices of v
        for (int i = 0; i < n; i++) {
            if (graph[v][i] && color[i] == c) {
                return false;  // If an adjacent vertex has the same color, return false
            }
        }
        return true;  // Safe to assign color c to vertex v
    }

    // Utility function to solve the problem using backtracking
    bool graphColoringUtil(bool graph[101][101], int m, int color[], int v, int n) {
        // Base case: If all vertices are colored, return true
        if (v == n) {
            return true;
        }

        // Try assigning each color from 1 to m
        for (int c = 1; c <= m; c++) {
            // Check if it's safe to color vertex v with color c
            if (isSafe(v, graph, color, c, n)) {
                // Assign color c to vertex v
                color[v] = c;

                // Recur to assign colors to the rest of the vertices
                if (graphColoringUtil(graph, m, color, v + 1, n)) {
                    return true;
                }

                // If assigning color c doesn't lead to a solution, backtrack
                color[v] = 0;
            }
        }

        // If no color can be assigned to this vertex, return false
        return false;
    }

    // Function to determine if the graph can be colored with at most M colors
    bool graphColoring(bool graph[101][101], int m, int n) {
        // Initialize a color array to store the color assignment for each vertex
        int color[n] = {0};  // Initially all vertices are uncolored (represented by 0)

        // Use the utility function to solve the problem
        if (graphColoringUtil(graph, m, color, 0, n)) {
            return true;  // If the graph can be colored, return true
        }

        return false;  // If the graph cannot be colored, return false
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends