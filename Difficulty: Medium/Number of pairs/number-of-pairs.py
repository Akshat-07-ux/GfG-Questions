from bisect import bisect_right

class Solution:
    def countPairs(self, arr, brr):
        # Count occurrences of 1, 2, 3, and 4 in brr because they are special cases
        brr.sort()
        count1 = brr.count(1)
        count2 = brr.count(2)
        count3 = brr.count(3)
        count4 = brr.count(4)
        
        total_pairs = 0
        
        for x in arr:
            if x == 1:
                # If x is 1, skip because 1^y < y^1 for all y > 1
                continue
            elif x == 2:
                # For x = 2, skip (2, 3) and (2, 4) as they don't satisfy the condition
                # Count all brr[j] > 2
                pos = bisect_right(brr, 2)
                total_pairs += len(brr) - pos
                # Add pairs with y = 1
                total_pairs += count1
                # Subtract pairs with y = 3 and y = 4
                total_pairs -= count3 + count4
            elif x == 3:
                # For x = 3, skip (3, 2) as it doesn't satisfy the condition
                # Count all brr[j] > 3
                pos = bisect_right(brr, 3)
                total_pairs += len(brr) - pos
                # Add pairs with y = 1
                total_pairs += count1
                # Add pairs with y = 2
                total_pairs += count2
            else:
                # For all other x > 3, count all brr[j] > x
                pos = bisect_right(brr, x)
                total_pairs += len(brr) - pos
                # Add pairs with y = 1
                total_pairs += count1
        
        return total_pairs


#{ 
 # Driver Code Starts
#Initial Template for Python 3

#Initial Template for Python 3

import atexit
import io
import sys
import bisect

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        # M, N = map(int, input().strip().split())
        a = list(map(int, input().strip().split()))
        b = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.countPairs(a, b))
        #code here

# } Driver Code Ends