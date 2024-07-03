//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    void deleteDuplicates(Node* &head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* prev = dummy;
        Node* current = head;
        
        while (current != nullptr) {
            bool isDuplicate = false;
            
            while (current->next != nullptr && current->data == current->next->data) {
                isDuplicate = true;
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            
            if (isDuplicate) {
                Node* temp = current;
                current = current->next;
                delete temp;
                continue;
            }
            
            prev->next = current;
            prev = prev->next;
            current = current->next;
        }
        
        prev->next = nullptr;
        head = dummy->next;
        delete dummy;
    }

    Node* removeAllDuplicates(struct Node* head) {
        deleteDuplicates(head);
        return head;
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends