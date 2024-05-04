//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution{
public:
//Function to return a tree created from postorder and inoreder traversals.
Node*buildTreeIN(int inorder[],int inStart,int inEnd,int postorder[],int postStart,int postEnd,map<int,int>&inMap){
        //Base case for Nulls in Tree
        if(inStart>inEnd||postStart>postEnd)return NULL;
        
        //Create a root node from end of postorder
        Node*root=new Node(postorder[postEnd]);

        //INDEX OF ROOT
        int inRoot=inMap[postorder[postEnd]];
        //Count of nodes in left subtree 
        int numsleft=inRoot-inStart;
        
        //Call the function recursively on left & right subtrees
        root->left=buildTreeIN(inorder,inStart,inRoot-1,postorder,postStart,postStart+numsleft-1,inMap);
        root->right=buildTreeIN(inorder,inRoot+1,inEnd,postorder,postStart+numsleft,postEnd-1,inMap);
        
        return root;
    }
    
Node *buildTree(int inorder[], int postorder[], int n) {
    
    map<int,int>inMap;
    for(int i=0;i<n;i++){
        inMap[inorder[i]]=i;
    }
    return buildTreeIN(inorder,0,n-1,postorder,0,n-1,inMap);   
}

};
    

//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends