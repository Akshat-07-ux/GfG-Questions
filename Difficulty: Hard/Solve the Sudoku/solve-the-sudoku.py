#User function Template for python3

class Solution:
 # Function to find a solved Sudoku.
    def SolveSudoku(self, grid):
        # Call the recursive backtracking function
        if self.solve(grid):
            return True
        return False
    
    def solve(self, grid):
        # Find an empty cell in the grid (represented by 0)
        for row in range(9):
            for col in range(9):
                if grid[row][col] == 0:  # An empty cell
                    # Try all possible values from 1 to 9
                    for num in range(1, 10):
                        if self.isSafe(grid, row, col, num):
                            grid[row][col] = num  # Place the number
                            # Recur to check if this leads to a solution
                            if self.solve(grid):
                                return True
                            # If not, backtrack
                            grid[row][col] = 0
                    return False  # No number could be placed, need to backtrack
        return True  # All cells are filled

    def isSafe(self, grid, row, col, num):
        # Check the row
        for x in range(9):
            if grid[row][x] == num:
                return False
        # Check the column
        for x in range(9):
            if grid[x][col] == num:
                return False
        # Check the 3x3 sub-box
        startRow, startCol = 3 * (row // 3), 3 * (col // 3)
        for i in range(3):
            for j in range(3):
                if grid[i + startRow][j + startCol] == num:
                    return False
        return True  # Safe to place the number

    # Function to print grids of the Sudoku.
    def printGrid(self, arr):
        for row in arr:
            print(' '.join(map(str, row)), end=' ')


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    t = int(input())
    while(t>0):
        grid = [[0 for i in range(9)] for j in range(9)]
        row = [int(x) for x in input().strip().split()]
        k = 0
        for i in range(9):
            for j in range(9):
                grid[i][j] = row[k]
                k+=1
                
        ob = Solution()
            
        if(ob.SolveSudoku(grid)==True):
            ob.printGrid(grid)
            print()
        else:
            print("No solution exists")
        t = t-1
# } Driver Code Ends