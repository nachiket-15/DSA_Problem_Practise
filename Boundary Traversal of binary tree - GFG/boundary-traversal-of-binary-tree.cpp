//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void printLeftBoundary(Node*root,vector<int>&ans){
        //Return if root is null or its a leaf node
        if(!root || (!root->left && !root->right)){
            return;
        }
        //print left most node and call recursive func
        ans.push_back(root->data);
        
        if(root->left){
            printLeftBoundary(root->left,ans);
        }else{
            printLeftBoundary(root->right,ans);
        }
    }
    
    void printLeaf(Node*root,vector<int>&ans){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            ans.push_back(root->data);
        }
        printLeaf(root->left,ans);
        printLeaf(root->right,ans);
    }
    
    void printRightBoundary(Node*root,vector<int>&ans){
        //Return if root is null or its a leaf node
        if(!root || (!root->left && !root->right)){
            return;
        }
        
        //First give recursive calls and print while backtracking
        if(root->right){
            printRightBoundary(root->right,ans);
        }else{
            printRightBoundary(root->left,ans);
        }
        //print while backtracking so that it will get printed in bottom up 
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        //Printing left boundary , then leaf nodes from left to right 
        //then printing right boundary bottom up
        
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        //root
        ans.push_back(root->data);
        //print left boundary except leaf in top down manner
        printLeftBoundary(root->left,ans);
        //print leaf from left to right
        printLeaf(root->left,ans);
        printLeaf(root->right,ans);
        //print right boundary bottom up
        printRightBoundary(root->right,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends