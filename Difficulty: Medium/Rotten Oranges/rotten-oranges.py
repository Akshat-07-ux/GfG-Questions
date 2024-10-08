from collections import deque
class Solution:

    #Function to find minimum time required to rot all oranges. 
	def orangesRotting(self, grid):
        # Get the dimensions of the grid
        n, m = len(grid), len(grid[0])
        
        # Queue to store the positions of all the rotten oranges
        queue = deque()
        fresh_count = 0  # To count fresh oranges

        # Initialize the queue with all the initially rotten oranges and count fresh ones
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    queue.append((i, j))  # Add rotten orange to the queue
                elif grid[i][j] == 1:
                    fresh_count += 1  # Count fresh oranges
        
        # If there are no fresh oranges, return 0 since no time is needed
        if fresh_count == 0:
            return 0
        
        # Directions array for moving up, down, left, and right
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        time = 0  # Variable to track the time taken to rot all oranges

        # Perform BFS
        while queue:
            # Increase time at each level of BFS (if there are rotten oranges spreading)
            time += 1
            for _ in range(len(queue)):
                x, y = queue.popleft()

                # Try all 4 possible directions (up, down, left, right)
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    # If the new position is within bounds and has a fresh orange
                    if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == 1:
                        grid[nx][ny] = 2  # Rotten the fresh orange
                        fresh_count -= 1  # Decrease the fresh orange count
                        queue.append((nx, ny))  # Add the new rotten orange to the queue
        
        # If there are still fresh oranges left, return -1, otherwise return time-1
        return time - 1 if fresh_count == 0 else -1

#{ 
 # Driver Code Starts
from queue import Queue


T=int(input())
for i in range(T):
	n, m = map(int, input().split())
	grid = []
	for _ in range(n):
		a = list(map(int, input().split()))
		grid.append(a)
	obj = Solution()
	ans = obj.orangesRotting(grid)
	print(ans)

# } Driver Code Ends