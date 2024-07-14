//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node*mark_parent(Node*root,map<Node*,Node*>&parent,int start){
        queue<Node*>q;
        q.push(root);
        Node*res=NULL;

        while(!q.empty()){
            Node*node=q.front();
            q.pop();

            if(node->data==start){
                res=node;
                //pointer to target node
            }

            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }

            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }
    int findTime(Node*target,map<Node*,Node*>&parent){
        queue<Node*>q;
        q.push(target);
        map<Node*,int>vis;
        vis[target]=1;

        int countMaxTime=0;
        while(!q.empty()){
            int size=q.size();
            int flag=0;

            for(int i=0;i<size;i++){
                Node*node=q.front();
                q.pop();
                
                if(node->left && vis[node->left]==0){
                    flag=1;
                    q.push(node->left);
                    vis[node->left]=1;
                }
                if(node->right && vis[node->right]==0){
                    flag=1;
                    q.push(node->right);
                    vis[node->right]=1;
                }
                if(parent[node] && vis[parent[node]]==0){
                    flag=1;
                    q.push(parent[node]);
                    vis[parent[node]]=1;
                }
            }
            if(flag)countMaxTime++;
        }
        return countMaxTime;
    }
    int amountOfTime(Node* root, int start) {
        map<Node*,Node*>parent;
        //get target node and also update parent map
        Node*target=mark_parent(root,parent,start);
        return findTime(target,parent);
    }
    int minTime(Node* root, int target) 
    {
        return amountOfTime(root,target);
    }
};



//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends