#User function Template for python3
class Solution:
    def removeDuplicates(self, str):
        seen = set()
        result = []
        
        # Traverse the string
        for char in str:
            # Add character to result if not seen before
            if char not in seen:
                result.append(char)
                seen.add(char)
        
        # Return the result as a string
        return ''.join(result)

#{ 
 # Driver Code Starts
#Initial Template for Python 3





if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        str = input().strip()
        ob = Solution()
        ans = ob.removeDuplicates(str)
        print(ans)
        tc -= 1

# } Driver Code Ends