#User function Template for python3

class Solution:
    def longestCommonPrefix(self, arr):
        min_word=min(arr)
        max_word=max(arr)
        
        length=len(min_word)
        ans=""
        
        for i in range(length):
            if min_word[i]==max_word[i]:
                ans+=min_word[i]
            else:
                break

        
        if ans:
            return ans
        else:
            return -1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        arr = [x for x in input().strip().split(" ")]

        ob = Solution()
        print(ob.longestCommonPrefix(arr))

# } Driver Code Ends