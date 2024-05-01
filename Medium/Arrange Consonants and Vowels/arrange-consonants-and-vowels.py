#User function Template for python3


class Node:
    def __init__(self, val):
        self.data = val
        self.next = None


class Solution:
    #Function to reverse a linked list.
    def arrangeCV(self, head):
        if head is None:
            return head
        
        array=[]
        
        while head:
            array.append(head.data)
            head=head.next
        
        vowel=[]
        consonants=[]
        
        for i in array:
            if i in ['a','e','i','o','u']:
                vowel.append(i)
            else:
                consonants.append(i)
        
        result=vowel+consonants
        
        resultList=None
        for data in reversed(result):
            # print(data)
            new_node=Node(data)
            new_node.next=resultList
            resultList=new_node
            
        return resultList


#{ 
 # Driver Code Starts


# Node Class    
class Node:
    def __init__(self, val):
        self.data = val
        self.next = None

# Linked List Class
class Linked_List:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, val):
        if self.head is None:
            self.head = Node(val)
            self.tail = self.head
        else:
            self.tail.next = Node(val)
            self.tail = self.tail.next

def printList(head):
    tmp = head
    while tmp:
        print(tmp.data, end=' ')
        tmp=tmp.next
    print()

if __name__=='__main__':
    for i in range(int(input())):
        n = int(input())
        arr = [str(x) for x in input().split()]
        
        lis = Linked_List()
        for i in arr:
            lis.insert(i)
        
        newHead = Solution().arrangeCV(lis.head)
        printList(newHead)

# } Driver Code Ends