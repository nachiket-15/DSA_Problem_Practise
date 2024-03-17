//{ Driver Code Starts
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

void append(struct Node** headRef, struct Node** tailRef, int newData) {
    struct Node* new_node = new Node(newData);

    if (*headRef == NULL) {
        *headRef = new_node;
    }

    else {
        (*tailRef)->next = new_node;
    }
    *tailRef = new_node;
}

void printList(struct Node* head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
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
class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        /*
        int cnt=0;
        
        while(head1)
        {
            int sum=head1->data;
            struct Node*temp=head2;
            while(temp)
            {
                sum+=temp->data;
                if(sum==x)cnt++;
                sum-=temp->data;
                
                temp=temp->next;
            }
            head1=head1->next;
        }
        return cnt;
        */
        
        unordered_set<int> st;

// Insert all values from head2 into the set
    struct Node* temp = head2;
    while (temp) {
        st.insert(temp->data);
        temp = temp->next;
    }
    
    int cnt = 0;
    
    // Iterate through head1
    while (head1) {
        // Check if (x - head1->data) exists in the set
        if (st.find(x - head1->data) != st.end()) {
            cnt++;
        }
        head1 = head1->next;
}

return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        struct Node* head1 = NULL;
        struct Node* tail1 = NULL;
        struct Node* tail2 = NULL;
        struct Node* head2 = NULL;
        int n1, n2, tmp, x;
        cin >> n1;
        while (n1--) {
            cin >> tmp;
            append(&head1, &tail1, tmp);
        }
        cin >> n2;
        while (n2--) {
            cin >> tmp;
            append(&head2, &tail2, tmp);
        }
        cin >> x;
        Solution obj;
        cout << obj.countPairs(head1, head2, x) << '\n';
    }
    return 0;
}
// } Driver Code Ends