//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //Min heap - {dist,node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        //Push the source node into it
        pq.push({0,S});//Dist,Node
        
        //Create a distance vector to store shortest distance of each node from source
        vector<int>dist(V,1e9);
        
        //Update distance of source from itself
        dist[S]=0;
        
        //Iterate till priority queue becomes empty
        while(!pq.empty()){
            
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            //Iterate over neighbours and relax the edges
            
            //Adjacency list is provided in question
            for(auto it:adj[node]){
                int adjN=it[0];
                int weight=it[1];
                
                //Relax the edges
                if(distance+weight<dist[adjN]){
                    
                    dist[adjN]=distance+weight;
                    pq.push({dist[adjN],adjN});
                    
                }
            }
        }
        return dist;
    }
};




//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends