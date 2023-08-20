//{ Driver Code Starts
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
    Node* root = new Node(stoi(ip[0]));
        
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
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isCousins(Node*root , int x , int y);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        int x , y;
        scanf("%d ",&x);
		scanf("%d ",&y);
        if(x==y)
        {
            cout<<"0\n";
            continue;
        }
        cout <<isCousins(root,x,y)<< endl;
    }
    return 1;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
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
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
void make_parent(Node*root,unordered_map<int,int>&parent)
{
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node*n=q.front();
        q.pop();
        
        if(n->left){
            parent[n->left->data]=n->data;
            q.push(n->left);
        }
        if(n->right){
            parent[n->right->data]=n->data;
            q.push(n->right);
        }
    }
    
}
int ht(Node*root,int a){
    int level=0;
    int height=0;
    
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        int size=q.size();
        level++;
        while(size--){
            Node*node=q.front();
            q.pop();
            if(node->data==a)return level;
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
    }
    return height;
}
bool isCousins(Node *root, int a, int b)
{
   //
   unordered_map<int,int>parent;
   make_parent(root,parent);
   
   int height1=ht(root,a);
   int height2=ht(root,b);
//   cout<<"ht 1: "<<height1<<" "<<"ht 2:"<<height2<<endl;
   
   int parent1=parent[a];
   int parent2=parent[b];
   //cout<<"Parent 1: "<<parent1<<" "<<"Parent 2:"<<parent2<<endl;
   
   if(parent1!=parent2 && height1==height2)return 1;
   
   return 0;
   
}