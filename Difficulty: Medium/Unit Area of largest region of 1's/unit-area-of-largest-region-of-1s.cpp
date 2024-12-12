//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int countFreq(vector<int>& arr, int target) {
        int first = findFirstOccurrence(arr, target);
        if (first == -1) {
            // Target is not present in the array
            return 0;
        }
        int last = findLastOccurrence(arr, target);
        return last - first + 1;
    }

    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());

        while (k-- > 0 && !maxHeap.empty()) {
            int maxGifts = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(floor(sqrt(maxGifts)));
        }

        long long totalGifts = 0;
        while (!maxHeap.empty()) {
            totalGifts += maxHeap.top();
            maxHeap.pop();
        }

        return totalGifts;
    }

    long long countWays(int n) {
        return n / 2 + 1;
    }

    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int maxArea = 0;
        vector<int> rowDir = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> colDir = {-1, 0, 1, -1, 1, -1, 0, 1};

        auto isSafe = [&](int x, int y) {
            return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !visited[x][y]);
        };

        function<int(int, int)> dfs = [&](int x, int y) {
            visited[x][y] = true;
            int area = 1;

            for (int k = 0; k < 8; ++k) {
                int newX = x + rowDir[k];
                int newY = y + colDir[k];
                if (isSafe(newX, newY)) {
                    area += dfs(newX, newY);
                }
            }
            return area;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    maxArea = max(maxArea, dfs(i, j));
                }
            }
        }

        return maxArea;
    }

private:
    int findFirstOccurrence(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                result = mid;
                high = mid - 1; // Search on the left side
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }

    int findLastOccurrence(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                result = mid;
                low = mid + 1; // Search on the right side
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends