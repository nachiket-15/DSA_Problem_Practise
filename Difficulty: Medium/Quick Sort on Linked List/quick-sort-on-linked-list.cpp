//{ Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}
// } Driver Code Ends




 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function
node* partition(node* head, node* tail) {
    //we select the first node as a pivot node 
    node* pivot = head;
    //prev and curr for shift the all smaller nodes data from the pivot node in left side 
    node* prev = head;
    node* curr = head->next;

    while (curr != tail->next) {
        if (curr->data < pivot->data) {
            
            //We start from next of prev as initially prev is pointing pivot ,as in this case head element is pivot
            swap(curr->data, prev->next->data);
            prev = prev->next;
        }
        curr = curr->next;
    }
    swap(pivot->data, prev->data);
    //return pre as a pivot
    return prev;
}

void quickSortHelper(node* head, node* tail) {
    //Edge case for recursive calls : if LL is empty or has only one element 
    if ( head == NULL || head == tail) {
        return;
    }
    
    //partition function for find the pivot 
    node* pivot = partition(head, tail);
    //Recursive call for left side
    quickSortHelper(head, pivot);
    //Recursive call for right side
    quickSortHelper(pivot->next, tail);
}
void quickSort(struct node **headRef) 
{
    node* head = *headRef;
    
    //Edge case: If the list is empty and the list has only one node 
    if (head== NULL || head->next==NULL){
        return;
    }
    
    //find the end node as a tail of list
    node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    
    node* tail = temp;
    quickSortHelper(head, tail);
}