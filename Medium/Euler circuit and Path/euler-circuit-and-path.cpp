//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	void dfs(int node,vector<int>adj[], vector<int>&vis){
          vis[node]=1;
          for(auto it:adj[node])
          {
              if(!vis[it])
              {
                   dfs(it,adj,vis);
              }
          }
      }
    int isEulerCircuit(int V, vector<int>adj[]){
        // Code here
        
        int temp=0;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                temp++;
            }
        }
       // if(temp>1)
       // return 0;
        vector<int>degree(V,0);
        int count=0;
        for(int i=0;i<V;i++)
        {
                degree[i]=adj[i].size();
                if(degree[i]%2==0)
                count++;
        }
        if(count==V && temp==1)
        return 2;
        else if(count==V-2)
        return 1;
        else 
        return 0;
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
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends