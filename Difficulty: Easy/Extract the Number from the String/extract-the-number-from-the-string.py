class Solution:
    def ExtractNumber(self,sentence):
        numbers=[]
        
        curr_num=''
        
        for char in sentence:
            if char.isdigit():
                curr_num+=char
            else:
                if curr_num :
                    if '9' not in curr_num:
                        numbers.append(int(curr_num))
                    curr_num=''
            
        # for last number , do same outside of loop
        if curr_num and '9' not in curr_num:
            numbers.append(int(curr_num))
        
        numbers.sort()
        
        if len(numbers)==0:
            return -1
        
        return numbers[-1]
        
        


#{ 
 # Driver Code Starts
t = int(input())
for _ in range(t):
    S = input()
    ob = Solution()
    ans = ob.ExtractNumber(S)
    print(ans)

# } Driver Code Ends