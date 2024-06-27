//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node*reverse(Node*head){
        Node*curr=head;
        Node*prev=NULL;
        Node*next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    void insertAtTail(Node*&head,Node*&tail,int val){
        Node*temp =new Node(val);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }else{
            tail->next=temp;
            tail=temp;
        }
    }
    
    Node*add(Node*first,Node*second){
        int carry=0;
        Node*ansHead=NULL;
        Node*ansTail=NULL;
        //Loop when both LL exists (Till equal len)
        while(first || second || carry)
        {
            int val1=0,val2=0;
        
            if(first){
                val1=first->data;
            }
            if(second){
                val2=second->data;
            }
            
            int sum=carry+val1+val2;
            int digit=sum%10;
            //Create nodes and add in answer Linked List
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            
            if(first){
                first=first->next;
            }
            if(second){
                second=second->next;
            }
        }
        return ansHead;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //Reverse the given lists
        first=reverse(first);
        second=reverse(second);
        
        //Add 2 lists
        Node*ans=add(first,second);
        
        //Reverse the ans
        ans=reverse(ans);
        //to avoid leading zeros in ans
        while(ans->data==0 && ans->next)ans=ans->next;
        
        return ans;
    }
};





//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends