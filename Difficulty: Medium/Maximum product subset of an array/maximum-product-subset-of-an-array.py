#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3
class Solution:
     def findMaxProduct(self, arr):
        MOD = 10**9 + 7
        n = len(arr)
        
        if n == 1:
            return arr[0]
        
        positives = []
        negatives = []
        zero_count = 0
        
        for num in arr:
            if num > 0:
                positives.append(num)
            elif num < 0:
                negatives.append(num)
            else:
                zero_count += 1
        
        # Special case: if there are no positive numbers and either no negatives or only one negative and some zeroes
        if not positives:
            if len(negatives) == 0:
                return 0
            if len(negatives) == 1 and zero_count > 0:
                return 0
        
        # Remove the negative number with the smallest absolute value if we have an odd count of negatives
        negatives.sort()
        if len(negatives) % 2 != 0:
            negatives.pop()
        
        product = 1
        for num in positives + negatives:
            product = (product * num) % MOD
        
        return product


#{ 
 # Driver Code Starts.
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    t = int(data[index])
    index += 1
    results = []
    
    for _ in range(t):
        n = int(data[index])
        index += 1
        arr = list(map(int, data[index:index + n]))
        index += n
        solution = Solution()
        ans = solution.findMaxProduct(arr)
        results.append(ans)
    
    for result in results:
        print(result)
# } Driver Code Ends