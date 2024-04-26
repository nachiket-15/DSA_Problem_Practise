#User function Template for python3

class Solution:
	def FindExitPoint(self,n,m,matrix):
        i, j, direction = 0, 0, 0
        
        while 0 <= i < n and 0 <= j < m:
            if matrix[i][j] == 1:
                direction = (direction + 1) % 4
                matrix[i][j] = 0
            
            if direction == 0:
                j += 1
            elif direction == 1:
                i += 1
            elif direction == 2:
                j -= 1
            elif direction == 3:
                i -= 1
        
        if i == -1:
            i = 0
        if j == -1:
            j = 0
        if i == n:
            i = n - 1
        if j == m:
            j = m - 1
        
        return i, j
	     
		 


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n, m = input().split()
        n = int(n)
        m = int(m)
        matrix = []
        for _ in range(n):
            matrix.append(list(map(int, input().split())))
        ob = Solution()
        ans = ob.FindExitPoint(n, m, matrix)
        for _ in ans:
            print(_, end=" ")
        print()

# } Driver Code Ends