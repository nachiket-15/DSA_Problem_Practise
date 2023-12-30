//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
  private:
    bool dfsCheck(int node,vector<int> adj[],vector<bool>&vis,vector<bool>&pathVis,vector<bool>&check){
        //Firstly mark vis and path vis array 
        vis[node]=1;
        pathVis[node]=1;
        //Give a dfs algo call by iterating over neighbours of currentnode
        
        for(auto neighbour:adj[node]){
            //If adjacent node is unvisited , check for cycle 
            if(!vis[neighbour]){
                //If cycle is present return true
                if(dfsCheck(neighbour,adj,vis,pathVis,check)==true)
                    return true;
            }
            //If adj node is visited & path visited - means there exists cycle
            else if(vis[neighbour] && pathVis[neighbour]){
                check[node]=0;
                return true;
            }
        }
        
        // If no cycle is detected for a node & it have reached here 
        check[node]=1;
        //While Backtracking unmark pathVis array
        pathVis[node]=0;
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        //Make a visited array 
        vector<bool>vis(V,0);
        //Make a path-visited array to detect cycle
        vector<bool>pathVis(V,0);
        //Make a check array to check non-cyclic nodes
        vector<bool>check(V,0);
        //Make ans array
        vector<int>ans;
        
        //Iterate through graphs and mark nodes as visited & check for cycle
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsCheck(i,adj,vis,pathVis,check);
            }
        }
        
        //Push the indexes which are safe nodes into ans vector
        for(int i=0;i<V;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends