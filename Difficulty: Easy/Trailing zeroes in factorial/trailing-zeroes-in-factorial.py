#User function Template for python3

class Solution:
    def trailingZeroes(self, N):
        count = 0
        # Keep dividing N by powers of 5 and add the quotient to the count
        while N >= 5:
            N //= 5
            count += N
        return count



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        N = int(input()) 
        ob = Solution()
        ans = ob.trailingZeroes(N)
        print(ans)
# } Driver Code Ends