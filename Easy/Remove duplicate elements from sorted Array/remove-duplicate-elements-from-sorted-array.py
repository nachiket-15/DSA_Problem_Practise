#User function template for Python

class Solution:	
	def remove_duplicate(self, arr, n):
		i=0
		
		for j in range(1,n):
		    if arr[i]!=arr[j]:
		        i+=1
		        arr[i]=arr[j]
		
		return i+1;


#{ 
 # Driver Code Starts
#Initial template for Python

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        N = int(input())
        A = list(map(int, input().strip().split()))
        ob = Solution()
        n = ob.remove_duplicate(A,N)
        for i in range(n):
            print(A[i], end=" ")
        print()


# } Driver Code Ends