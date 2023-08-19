//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node,int parent,vector<int> adj[],vector<int>&vis){
        vis[node]=1;
        bool ans=false;
        for(auto adjacentNode:adj[node]){
            if(vis[adjacentNode]==1 && adjacentNode==parent){
                continue;
            }
            if(vis[adjacentNode]==1 && adjacentNode!=parent){
                return true;
            }
            ans=dfs(adjacentNode,node,adj,vis);
        }
        return ans;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Detect cycle by dfs
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                //node,parent,adjacency list,visited array
                if(dfs(i,-1,adj,vis))return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends