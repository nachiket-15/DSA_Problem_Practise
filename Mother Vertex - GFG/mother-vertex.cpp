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
	    //Then referred solution
	    
	    //First of all create ans var and visited vector
	    int ans=0;
	    vector<int>vis(V,0);
	    
	    //Apply dfs calls for each vertex if its unvisited
	    for(int i=0;i<V;i++){
	        //This will provide us with vertex who was lastly called for dfs
	        if(vis[i]==0){
	            //Store latest dfs call vertex
	            ans=i;
	            dfs(i,adj,vis);
	        }
	    }
	    //Again initialize the visited vertex with all zeros
	    vis=vector<int>(V,0);
	    //Again have a dfs call
	    dfs(ans,adj,vis);
	    //Now check for visited array , if found any element 
	    //unvisited then its not possible to visit all nodes 
	    //from a vertex
	    for(auto n:vis){
	        if(n==0)return -1;
	    }
	    //Else return the last vertex for which dfs call was done as 
	    //all vertices are visited in its dfs call
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