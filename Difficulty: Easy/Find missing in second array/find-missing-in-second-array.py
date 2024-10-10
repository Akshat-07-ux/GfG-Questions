#User function Template for python3


class Solution:
     def findMissing(self, a, b, n, m):
        # Convert array b to a set for O(1) lookups
        set_b = set(b)
        
        # List to store the result
        result = []
        
        # Traverse array a and check if the element is in set_b
        for num in a:
            if num not in set_b:
                result.append(num)
        
        return result



#{ 
 # Driver Code Starts
#Initial Template for Python 3



t=int(input())
for _ in range(0,t):
   # n=int(input())
    l = list(map(int, input().split()))
    n=l[0]
    m=l[1]
    a = list(map(int,input().split()))
    b = list(map(int, input().split()))
    ob=Solution()
    ans=ob.findMissing(a,b,n,m)
    for each in ans:
        print(each,end=' ')
    print()
# } Driver Code Ends