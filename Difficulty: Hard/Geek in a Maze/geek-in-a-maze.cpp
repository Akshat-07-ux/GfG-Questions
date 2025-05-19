//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int numberOfCells(int n, int m, int r, int c, int u, int d,
                      vector<vector<char>> &mat) {
        if (mat[r][c] == '#') return 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        deque<tuple<int, int, int, int>> dq;
        dq.push_back(std::make_tuple(r, c, 0, 0));
        visited[r][c] = true;

        int count = 1;
        while (!dq.empty()) {
            int x = std::get<0>(dq.front());
            int y = std::get<1>(dq.front());
            int up = std::get<2>(dq.front());
            int down = std::get<3>(dq.front());
            dq.pop_front();

            for (int dx : {-1, 1}) {
                int ny = y + dx;
                if (ny >= 0 && ny < m && !visited[x][ny] && mat[x][ny] == '.') {
                    visited[x][ny] = true;
                    dq.push_front(std::make_tuple(x, ny, up, down));
                    count++;
                }
            }

            if (x - 1 >= 0 && up < u && !visited[x - 1][y] && mat[x - 1][y] == '.') {
                visited[x - 1][y] = true;
                dq.push_back(std::make_tuple(x - 1, y, up + 1, down));
                count++;
            }

            if (x + 1 < n && down < d && !visited[x + 1][y] && mat[x + 1][y] == '.') {
                visited[x + 1][y] = true;
                dq.push_back(std::make_tuple(x + 1, y, up, down + 1));
                count++;
            }
        }

        return count;
    }
};


//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;

    while (t--)
    {
    	int n, m, r, c, u, d;
        cin >> n >> m >> r >> c >> u >> d;
        
        vector<vector<char>> mat(n, vector<char>(m, '.'));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        		cin >> mat[i][j];
        	}
        }

      

        Solution obj;
        cout << obj.numberOfCells(n, m, r, c, u, d, mat) << "\n";
    
    
cout << "~" << "\n";
}

    return 0;
}



// } Driver Code Ends