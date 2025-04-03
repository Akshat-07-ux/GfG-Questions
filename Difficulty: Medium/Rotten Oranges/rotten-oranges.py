from collections import deque

class Solution:
    def orangesRotting(self, mat):
        if not mat:
            return -1

        n, m = len(mat), len(mat[0])
        queue = deque()
        fresh_count = 0

        # Step 1: Collect all initially rotten oranges and count fresh ones
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 2:
                    queue.append((i, j, 0))  # (row, col, time)
                elif mat[i][j] == 1:
                    fresh_count += 1

        # If there are no fresh oranges, return 0
        if fresh_count == 0:
            return 0

        # Step 2: BFS to rot fresh oranges
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        time_elapsed = 0

        while queue:
            i, j, time = queue.popleft()
            time_elapsed = max(time_elapsed, time)

            for di, dj in directions:
                ni, nj = i + di, j + dj
                if 0 <= ni < n and 0 <= nj < m and mat[ni][nj] == 1:
                    mat[ni][nj] = 2  # Rot the fresh orange
                    fresh_count -= 1
                    queue.append((ni, nj, time + 1))

        # If there are still fresh oranges left, return -1
        return -1 if fresh_count > 0 else time_elapsed

#{ 
 # Driver Code Starts
from queue import Queue

T = int(input())
for i in range(T):
    n = int(input())
    m = int(input())
    mat = []
    for _ in range(n):
        a = list(map(int, input().split()))
        mat.append(a)
    obj = Solution()
    ans = obj.orangesRotting(mat)
    print(ans)
    print("~")

# } Driver Code Ends