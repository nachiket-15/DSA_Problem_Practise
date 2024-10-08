//{ Driver Code Starts
// Initial template for C++

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

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
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
    void insertAtTail(Node*&head,Node*&tail,int val)
    {
        Node*temp=new Node(val);
        
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    
    Node*add(Node*first)
    {
        Node*ansHead=NULL;
        Node*ansTail=NULL;
        
        int carry=1;
        
        while(first || carry){
            int sum=0;
            
            if(first){
                sum+=first->data;
            }
            if(carry){
                sum+=carry;
            }
            int digit=sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry=(sum/10);
            
            if(first)first=first->next;
        }
        
        return ansHead;
    }
    
    Node* addOne(Node *head) 
    {
        head=reverse(head);
        Node*ans=add(head);
        ans=reverse(ans);
        return ans;
    }
    
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends