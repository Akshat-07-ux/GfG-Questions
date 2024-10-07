#User function Template for python3

class Solution:
    def AllPossibleStrings(self, s):
        n = len(s)
        subsequences = []

        # Generate all possible subsequences using bitmasking
        for i in range(1, 1 << n):  # 1 << n is 2^n, excluding 0 for non-empty subsequences
            subsequence = []
            for j in range(n):
                if i & (1 << j):  # If the jth bit is set in i, include s[j]
                    subsequence.append(s[j])
            subsequences.append(''.join(subsequence))
        
        # Sort the subsequences lexicographically
        subsequences.sort()

        return subsequences

#{ 
 # Driver Code Starts

#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		s = input()
		ob = Solution();
		ans = ob.AllPossibleStrings(s)
		for i in ans:
			print(i, end = " ");
		print()
# } Driver Code Ends