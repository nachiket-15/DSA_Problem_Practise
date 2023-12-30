//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void solve(int node,stack<int>&st,vector<bool>&vis,vector<int> adj[]){
        //Mark this node as visited
        vis[node]=1;
        // Call dfs for adjacent nodes 
        for(auto neighbour: adj[node]){
            if(!vis[neighbour]){
                solve(neighbour,st,vis,adj);
            }
        }
        // When dfs call reaches a node having 0 outdegree 
        // Then push elements into stack
        
        //Or push into stack when all its adjacent elements are already present
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //Make a visited array
	    vector<bool>vis(V,0);
	    //Create a stack to store elements 
	    stack<int>st;
	    //Create a vector array to return as ans
	    vector<int>ans;
	    
	    //Traverse the elements
	    for(int i=0;i<V;i++){
	        //If an element is unvisited , call solve function
	        //Mark node as visited and push node's neighbour in stack
	        //If they are unvisited by rec call
	        
	        //Pushing is done onto stack if all its neighbours are already pushed
	        if(!vis[i]){
	            solve(i,st,vis,adj);
	        }
	    }
	    
	    //Put stack elements into ans vector and return it 
	    while(!st.empty()){
	        int data=st.top();
	        st.pop();
	        ans.push_back(data);
	    }
	    return ans;
	}
};



//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends