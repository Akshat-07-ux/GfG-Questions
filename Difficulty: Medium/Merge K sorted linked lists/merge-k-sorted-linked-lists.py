#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3
'''
class Node:
    def _init_(self,x):
        self.data = x
        self.next = None
'''
import heapq

class Solution:
    def mergeKLists(self, arr):
        # Create a min heap to store tuples of (node value, node)
        heap = []
        
        # Dummy head for the result list
        dummy = Node(0)
        current = dummy
        
        # Push the head of each non-empty list into the heap
        # We use an additional index to handle potential value conflicts
        for i, head in enumerate(arr):
            if head:
                heapq.heappush(heap, (head.data, i, head))
        
        # Process the heap until it's empty
        while heap:
            # Pop the smallest element
            val, index, node = heapq.heappop(heap)
            
            # Add to result list
            current.next = node
            current = current.next
            
            # Move to next node in the original list
            if node.next:
                heapq.heappush(heap, (node.next.data, index, node.next))
        
        # Return the merged list (skip dummy head)
        return dummy.next

#{ 
 # Driver Code Starts.
#Initial Template for Python 3
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def print_list(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()



def main():
    t = int(input().strip())
    for _ in range(t):
        arr = []
        nums = list(map(int, input().strip().split()))
        ind = 0
        N = len(nums)
        
        while ind < N:
            n = nums[ind]
            ind += 1
            x = nums[ind]
            ind += 1
            head = Node(x)
            curr = head
            n -= 1

            for _ in range(n):
                x = nums[ind]
                ind += 1
                temp = Node(x)
                curr.next = temp
                curr = temp

            arr.append(head)

        solution = Solution()
        res = solution.mergeKLists(arr)
        print_list(res)
        print("~")

if __name__ == "__main__":
    main()

# } Driver Code Ends