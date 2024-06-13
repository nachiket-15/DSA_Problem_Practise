#User function Template for python3

class Solution:
    def longestUniqueSubsttr(self, S):
        # code here
        d={}
        l=0
        mlen=0
        for r in range(len(S)):
            if S[r] in d and d[S[r]]>=l:
                l=d[S[r]]+1
            d[S[r]]=r
            mlen=max(mlen,r-l+1)
        return mlen


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        s = input().strip()
        
        
        ob=Solution()
        print(ob.longestUniqueSubsttr(s))
# } Driver Code Ends