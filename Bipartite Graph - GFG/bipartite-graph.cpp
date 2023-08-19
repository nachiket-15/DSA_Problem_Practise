//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    private:
    bool check(int start,vector<int>&color,vector<int>adj[]){
        queue<int>q;
        q.push(start);
        color[start]=0;
        
        while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        
	        for(auto neighbour:adj[node]){
	            if(color[neighbour]==-1){
	                color[neighbour]=(!color[node]);
	                q.push(neighbour);
	            }
	            if(color[neighbour]==color[node]){
	                return false;
	            }
	        }
	    }
	    
	    return true;
    }
    public:
	bool isBipartite(int V, vector<int>adj[]){
	    //We will form a color vector 
	    
	    //Basically a BFS traversal is used
	    vector<int>color(V,-1);
	    
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(check(i,color,adj)==0)
	                return false;
	        }
	    }
	    
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends