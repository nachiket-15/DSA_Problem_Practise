#User function Template for python3

class Solution:
    def longestCommonPrefix(self, str1, str2):
        longest = [-1, -1]
        
        for i in range(len(str1)):
            if str1[:i] not in str2:
                return longest
            else:
                longest = [0, i-1]
        return longest


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        str1 = input()
        str2 = input()
        ob = Solution()
        ans = ob.longestCommonPrefix(str1, str2)
        if ans[0] == -1:
            print(-1)
        else:
            print(ans[0], ans[1])

# } Driver Code Ends