#User function Template for python3
import heapq
class Solution:
     # Function to merge k sorted arrays.
    def mergeKArrays(self, arr, K):
        # Create a min-heap to store the elements along with the index of the array they belong to
        min_heap = []
        
        # Initialize the heap with the first element of each array
        for i in range(K):
            # Push (value, array index, element index) to the heap
            heapq.heappush(min_heap, (arr[i][0], i, 0))

        merged_list = []
        
        # Extract the smallest element from the heap and add the next element from the same array to the heap
        while min_heap:
            value, array_index, element_index = heapq.heappop(min_heap)
            merged_list.append(value)

            # If there is a next element in the same array, push it to the heap
            if element_index + 1 < K:
                next_value = arr[array_index][element_index + 1]
                heapq.heappush(min_heap, (next_value, array_index, element_index + 1))
        
        return merged_list


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    t=int(input())
    for _ in range(t):
        n=int(input())
        numbers=[[ 0 for _ in range(n) ] for _ in range(n) ]
        line=input().strip().split()
        for i in range(n):
            for j in range(n):
                numbers[i][j]=int(line[i*n+j])
        ob = Solution();
        merged_list=ob.mergeKArrays(numbers, n)
        for i in merged_list:
            print(i,end=' ')
        print()
# } Driver Code Ends