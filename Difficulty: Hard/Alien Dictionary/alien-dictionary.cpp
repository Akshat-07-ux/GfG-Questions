//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
 public:
    string findOrder(string dict[], int N, int K) {
        // Create a graph with K nodes
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> inDegree;
        unordered_set<char> uniqueChars;
        
        // Initialize graph and in-degree for each character
        for (int i = 0; i < N; ++i) {
            for (char ch : dict[i]) {
                if (inDegree.find(ch) == inDegree.end()) {
                    inDegree[ch] = 0;
                    graph[ch] = unordered_set<char>();
                }
                uniqueChars.insert(ch);
            }
        }
        
        // Build the graph by comparing adjacent words
        for (int i = 1; i < N; ++i) {
            string word1 = dict[i - 1];
            string word2 = dict[i];
            int minLength = min(word1.size(), word2.size());
            bool foundDifference = false;
            
            for (int j = 0; j < minLength; ++j) {
                if (word1[j] != word2[j]) {
                    if (graph[word1[j]].find(word2[j]) == graph[word1[j]].end()) {
                        graph[word1[j]].insert(word2[j]);
                        inDegree[word2[j]]++;
                    }
                    foundDifference = true;
                    break;
                }
            }
            if (!foundDifference && word1.size() > word2.size()) {
                // This is an invalid dictionary case but assuming valid input here
                return "";
            }
        }
        
        // Perform topological sort using Kahn's Algorithm
        queue<char> zeroInDegree;
        for (auto& entry : uniqueChars) {
            if (inDegree[entry] == 0) {
                zeroInDegree.push(entry);
            }
        }
        
        string order = "";
        while (!zeroInDegree.empty()) {
            char current = zeroInDegree.front();
            zeroInDegree.pop();
            order += current;
            
            for (char neighbor : graph[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    zeroInDegree.push(neighbor);
                }
            }
        }
        
        // Check if we have included all characters
        if (order.size() != uniqueChars.size()) {
            return ""; // There was a cycle
        }
        
        return order;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends