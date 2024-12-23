//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // Sort both arrays in descending order
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());

        // Max-heap to store sums and indices
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        // Push initial sum and indices (0,0)
        maxHeap.push({A[0] + B[0], {0, 0}});

        // Set to track visited indices
        set<pair<int, int>> visited;
        visited.insert({0, 0});

        vector<int> result;

        // Extract up to K sums
        for (int i = 0; i < K; ++i) {
            if (maxHeap.empty()) break;

            // Extract the max sum
            auto current = maxHeap.top();
            maxHeap.pop();
            result.push_back(current.first);

            int x = current.second.first;
            int y = current.second.second;

            // Check and add next two possible combinations
            if (x + 1 < N && visited.find({x + 1, y}) == visited.end()) {
                maxHeap.push({A[x + 1] + B[y], {x + 1, y}});
                visited.insert({x + 1, y});
            }

            if (y + 1 < N && visited.find({x, y + 1}) == visited.end()) {
                maxHeap.push({A[x] + B[y + 1], {x, y + 1}});
                visited.insert({x, y + 1});
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends