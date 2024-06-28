#User function Template for python3

class Solution:
    def pattern (self, arr):
        # code here
        #for rows
        for i in range(len(arr)):
            cl=arr[i]
            #print(cl)
            cs=''.join([str(x) for x in cl])
            #print(cs)
             #cs=''.join(cl)
            if cs==cs[::-1]:
                return str(i)+' R'
        
        #for columns
        for i in range(len(arr[0])):
            col=[str(arr[j][i]) for j in range(len(arr))]
            cs=''.join(col)
            
            if cs==cs[::-1]:
                return str(i)+' C'
        
        return -1



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    ob = Solution()
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        a = list()
        c = 0
        for i in range(0, n):
            X = list()
            for j in range(0, n):
                X.append(arr[c])
                c += 1
            a.append(X)
        ans = ob.pattern(a)
        print(ans)

# } Driver Code Ends