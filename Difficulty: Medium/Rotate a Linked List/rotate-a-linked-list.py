# Your task is to complete this function

'''

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

'''


class Solution:
    
    
    #Function to rotate a linked list.
    def rotate(self, head, k):
        # Edge cases: empty list, single node, or k = 0
        if not head or not head.next or k == 0:
            return head
        
        # Step 1: Find the kth node and the last node
        current = head
        for _ in range(k - 1):
            if not current.next:
                return head  # k is equal to or greater than list length
            current = current.next
        
        # If k is equal to list length, no rotation needed
        if not current.next:
            return head
        
        # Step 2: Rotate the list
        new_head = current.next
        current.next = None
        
        # Find the last node of the rotated list
        last = new_head
        while last.next:
            last = last.next
        
        # Connect the last node to the original head
        last.next = head
        
        return new_head



#{ 
 # Driver Code Starts
#Initial Template for Python 3


# Define the Node class for the linked list
class Node:

    def __init__(self, x):
        self.data = x
        self.next = None


# Function to print the linked list
def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()


#Position this line where user code will be pasted.

# Main function
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    t = int(data[0].strip())
    idx = 1

    while t > 0:
        arr = list(map(int, data[idx].strip().split()))

        head = None
        if arr:
            head = Node(arr[0])
            tail = head
            for num in arr[1:]:
                tail.next = Node(num)
                tail = tail.next

        k = int(data[idx + 1].strip())
        idx += 2
        head = Solution().rotate(head, k)
        printList(head)
        t -= 1

# } Driver Code Ends