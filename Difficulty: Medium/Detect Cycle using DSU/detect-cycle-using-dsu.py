class Solution:

    # Function to detect cycle using DSU in an undirected graph.
    def detectCycle(self, V, adj):
        # Helper function to find the parent (with path compression)
        def find(parent, node):
            if parent[node] != node:
                parent[node] = find(parent, parent[node])
            return parent[node]
        
        # Helper function to perform union of two sets
        def union(parent, rank, u, v):
            rootU = find(parent, u)
            rootV = find(parent, v)
            
            # If roots are the same, there's a cycle
            if rootU == rootV:
                return True
            
            # Union by rank
            if rank[rootU] > rank[rootV]:
                parent[rootV] = rootU
            elif rank[rootU] < rank[rootV]:
                parent[rootU] = rootV
            else:
                parent[rootV] = rootU
                rank[rootU] += 1
            
            return False
        
        # Initialize DSU structures
        parent = [i for i in range(V)]
        rank = [0] * V
        
        # Iterate through all edges
        for u in range(V):
            for v in adj[u]:
                if u < v:  # Avoid double-checking edges in undirected graph
                    if union(parent, rank, u, v):
                        return 1  # Cycle detected
        
        return 0  # No cycle detected



#{ 
 # Driver Code Starts
if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        V, E = map(int, input().split())
        adj = [[] for i in range(V)]
        for _ in range(E):
            u, v = map(int, input().split())
            adj[u].append(v)
            adj[v].append(u)
        obj = Solution()
        ans = obj.detectCycle(V, adj)
        print(ans)
        print("~")

# } Driver Code Ends