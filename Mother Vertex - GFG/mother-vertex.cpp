//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int node, vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        
        for(auto neighbour:adj[node]){
            if(!vis[neighbour]){
                dfs(neighbour,adj,vis);
            }
        }
    }
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	    //Was able to pass 1213/1223 testcases on my own approach
	    int ans=0;
	    vector<int>vis(V,0);
	    
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            ans=i;
	            dfs(i,adj,vis);
	        }
	    }
	    vis=vector<int>(V,0);
	    dfs(ans,adj,vis);
	    for(auto n:vis){
	        if(n==0)return -1;
	    }
	    
	    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends