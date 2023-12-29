//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void bfs(int vertex,vector<int>adj[], int V,int *visited){
        visited[vertex]=1;
        queue<int>q;
        q.push(vertex);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x:adj[node]){
                if(!visited[x]){
                    visited[x]=1;
                    q.push(x);
                }
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        //Try converting adj matrix to list
        vector<int>adjL[V];
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
        
        int visited[V]={0};
        int count=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bfs(i,adjL,V,visited);
                count++;
            }
        }
        
        return count;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends