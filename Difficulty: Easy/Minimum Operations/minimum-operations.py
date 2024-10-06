#User function Template for python3

class Solution:
     def minOperation(self, n):
        # Initialize the number of operations
        operations = 0
        
        # Start from N and work backwards towards 0
        while n > 0:
            # If the number is even, divide by 2 (reverse of doubling)
            if n % 2 == 0:
                n //= 2
            # If the number is odd, subtract 1 (reverse of adding 1)
            else:
                n -= 1
            # Increment the count of operations
            operations += 1
        
        return operations


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        n = int(input())
        ob = Solution()
        print(ob.minOperation(n))
# } Driver Code Ends