//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node*sortedMerge(Node*left,Node*right)
    {
        if(left==NULL)return right;
        if(right==NULL)return left;
        
        Node*result=NULL;
        
        if(left->data<right->data){
            result=left;
            result->next=sortedMerge(left->next,right);
        }
        else{
            result=right;
            result->next=sortedMerge(left,right->next);
        }
        return result;
    }
    Node*findMid(Node*head)
    {
        Node*slow=head;
        Node*fast=head;
        
        while(slow->next && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
    Node* mergeSort(Node* head) 
    {
        if(head==NULL || head->next==NULL)
            return head;
        
        Node*left=head;
        Node*mid=findMid(head);
        Node*right=mid->next;
        
        //Break the LL into two parts now 
        mid->next=NULL;
        
        //Recursively break the linked list into left and right parts
        left=mergeSort(left);
        right=mergeSort(right);
        
        //Sorted merge the left and right halves of LinkedList
        Node*ans=sortedMerge(left,right);
        return ans;
    }
};




//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends