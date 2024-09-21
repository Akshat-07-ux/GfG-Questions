class MyStack:
    class StackNode:
        # Constructor to initialize a node
        def __init__(self, data):
            self.data = data
            self.next = None

    def __init__(self):
        self.top = None  # Initialize the top of the stack as None

    # Function to push an integer into the stack.
    def push(self, data):
        new_node = self.StackNode(data)  # Create a new node with the given data
        new_node.next = self.top  # Link the new node to the previous top
        self.top = new_node  # Update the top to be the new node

    # Function to remove an item from the top of the stack.
    def pop(self):
        if self.top is None:  # If the stack is empty
            return -1  # Return -1
        popped_data = self.top.data  # Get the data from the top node
        self.top = self.top.next  # Update the top to the next node
        return popped_data  # Return the popped data



#{ 
 # Driver Code Starts
class StackNode:

    # Constructor to initialize a node
    def __init__(self, data):
        self.data = data
        self.next = None


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    T = int(data[0])
    idx = 1
    for _ in range(T):
        sq = MyStack()
        line = data[idx].strip()
        nums = list(map(int, line.split()))
        idx += 1
        n = len(nums)
        i = 0
        while i < n:
            QueryType = nums[i]
            i += 1
            if QueryType == 1:
                a = nums[i]
                i += 1
                sq.push(a)
            elif QueryType == 2:
                print(sq.pop(), end=" ")
        print()

# } Driver Code Ends