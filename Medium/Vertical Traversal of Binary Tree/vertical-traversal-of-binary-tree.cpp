//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //vertical,level(horizontal),vector of nodes
        map<int,map<int,vector<int>>>nodes;
        
        //Make queue(Node,Vertical,Level)
        queue<pair<Node*,pair<int,int>>>todo;
        
        //Push root , vertical=0 & level=0
        todo.push({root,{0,0}});

        //BFS
        while(!todo.empty())
        {
            auto p=todo.front();
            todo.pop();
            Node*node=p.first;
            int vertical=p.second.first;
            int level=p.second.second;
            
            //Insert into vector
            nodes[vertical][level].push_back(node->data);

            if(node->left){
                todo.push({node->left,{vertical-1,level+1}});
            }
            if(node->right){
                todo.push({node->right,{vertical+1,level+1}});
            }
        }
        //At the end of above loop , all nodes have gone through bfs and inserted into vector
        vector<int>ans;

        //Map structure {vertical,{level,vector of nodes}}
        //Now iterate over it
        for (auto p:nodes){
            
            //make a single vector & then iterate over level
            for(auto q: p.second){
                
                //Iterate over vector of nodes
                for(auto r:q.second){
                    ans.push_back(r);
                }
            }
        }
        
        //As it was directed map , while iterating on map structure 
        //nodes in vector were as from left to right in particular verticle level
        
        //Its like u were saying 
        //Pratyek vertical sathi 
        //Go in all its level and print corresponding vector of nodes
        return ans;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends