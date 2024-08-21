//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        //As weights are unit weights , Simple bfs traversal with slight modf
        //worked out
        
        //Create adjacency list for undirected graph 
        vector<int>adj[N];
        for(auto it:edges){
            //As it is undirected graph
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        //Queue for bfs trav
        queue<int>q;
        //Initialize dist array with initial infinite value
        vector<int>dist(N,1e9);
        // int dist[N];
        // for(int i=0;i<N;i++)dist[i]=INT_MAX;
        
        
        //for given source node
        dist[src]=0;
        q.push(src);
        
        //Start bfs
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto neighbour:adj[node]){
                //check for condition
                if(dist[node]+1<dist[neighbour]){
                    //push it
                    q.push(neighbour);
                    dist[neighbour]=1+dist[node];
                }
            }
        }
        
        for(int i=0;i<N;i++)if(dist[i]==1e9)dist[i]=-1;
        
        // vector<int>ans(N,-1);
        // for(int i=0;i<N;i++)ans[i]=dist[i];
        
        return dist;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends