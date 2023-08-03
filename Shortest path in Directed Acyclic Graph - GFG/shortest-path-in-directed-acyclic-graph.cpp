//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    void topoSort(int start,vector<pair<int,int>>adj[],vector<int>&vis,stack<int>&st){
        vis[start]=1;
        for(auto it:adj[start]){
            int v=it.first;
            int wt=it.second;
            if(!vis[v]){
                topoSort(v,adj,vis,st);
            }
        }
        st.push(start);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        //Create an adjacency list ,given edges graph has src , dest & wt
        //Structure neighbouring_node,its weight
        vector<pair<int,int>>adj[N];
        
        for(auto v:edges){
            int c=v[0];//c-current node
            int n=v[1];//n-neighbouring node
            int wt=v[2];//wt-weight of neighbouring node
            adj[c].push_back({n,wt});
        }
        
        vector<int>vis(N,0);
        stack<int>st;
        
        for(int i=0;i<N;i++){
            if(!vis[i]){
                topoSort(i,adj,vis,st);
            }
        }
        
        vector<int>dist(N);
        for(int i=0;i<N;i++){
            dist[i]=1e9;
        }
        
        dist[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            if(dist[node]!=1e9){
                for(auto it:adj[node]){
                    int v=it.first;
                    int wt=it.second;
                    if(dist[node]+wt<dist[v]){
                        dist[v]=dist[node]+wt;
                    }
                }
            }
        }
        
        
        for(int i=0;i<N;i++)if(dist[i]==1e9)dist[i]=-1;
        
        return dist;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends