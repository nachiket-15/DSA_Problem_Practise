#User function Template for python3

class Solution:
    def findMaxSum(self,n,m,arr):
        result=-1
        
        for i in range(n-2):
            for j in range(m-2):
                temp=sum(arr[i][j:j+3])
                temp+=arr[i+1][j+1]
                temp+=sum(arr[i+2][j:j+3])
                
                result=max(result,temp)
        
        return result


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math
      
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        N,M=map(int,input().strip().split(" "))
        Mat=[]
        for i in range(N):
            B=list(map(int,input().strip().split(" ")))
            Mat.append(B)
        ob=Solution()
        ans=ob.findMaxSum(N,M,Mat)
        print(ans) 
# } Driver Code Ends