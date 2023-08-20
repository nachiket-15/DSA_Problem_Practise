//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        
	    //Form a adjacency list
	    vector<int>adj[n];
	    
	    //See and form according to given condition in prob statement
	    for(auto it: prerequisites){
	        adj[it[1]].push_back(it[0]);
	    }
	    
	   vector<int>ans;
	    //Form the indegree array
	    int indegree[n]={0};
	    //Fill the indegree array
	    for(int i=0;i<n;i++){
	        //For those elements in adj list which are on right side , 
	        //have indegree 1 from element on leftside
	        
	        //So do this for every iteration for finding its indegree
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    //Push the elements into queue with indegree as 0
	    for(int i=0;i<n;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    //Have bfs traversal - Modified according to kahns algorithm
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        //Popped element should be added into ans vector
	        ans.push_back(node);
	        
	        //Traverse over its neighbours 
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    
	    
	    //Basic logic here implemented was preparing topological sorting array
	    //If it has cycle then it is not possible to work acc to question
	    //condition
	    //Cycle was detected with help of topo array with below condition.
	    if(ans.size()==n){
	        return ans;
	    }
	    //Toposort fails on cycles , in toposort(bfs) we reduce indegree 
	    //array but in a cycle a cyclic dependency is form which does'
	    //not allows us to create toposort array and we end up creating 
	    //mostly small size array , so its size will be unequal with total
	    //no of tasks
	    
	    return {};
    }
};


//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends