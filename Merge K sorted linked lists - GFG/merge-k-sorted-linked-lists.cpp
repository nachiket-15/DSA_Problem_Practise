//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 
Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node*result=NULL;
    if(head1->data<=head2->data){
        result=head1;
        result->next=sortedMerge(head1->next,head2);
    }else{
        result=head2;
        result->next=sortedMerge(head1,head2->next);
    }return result;
}  

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        
        int last=K-1;
        
        while(last>0){
            int i=0,j=last;
            
            while(i<j){
                arr[i]=sortedMerge(arr[i],arr[j]);
                i++,j--;
                
                if(i>=j){
                    last=j;
                }
            }
        }
        
        return arr[0];
    }
};




//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends