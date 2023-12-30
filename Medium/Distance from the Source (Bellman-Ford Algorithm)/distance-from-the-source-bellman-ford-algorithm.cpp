//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>dist(V,1e8);
        dist[S]=0;
        
        //After N-1 iterations we get all shortest distance from source nodes
        for(int i=0;i<V-1;i++){
            
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                
                if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
            
        }
        //Why N-1 but ?? --> If we take a graph 0-1-2-3-4 with unit
        //distance between them 
        //Now if u perform algorithm dist between 0-1 will get updates
        //after first iteration , similarly distance between 1 & 2 will 
        //get updated after second iteration 
        //distance between 2&3 gets updated after third iteration 
        //distance between 3&4 gets updated after fourth iteration
        //So see after N-1 iterations ,worst graph too gets updated
        
        
        //So if there is negative cycle , values will still reduce 
        //So we will just check for last iteration do relaxation of edges happens or not
        
        
        //For negative cycle
        for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                
                if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                    return {-1};
                }
        }
        
        return dist;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends