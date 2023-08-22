//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int node,int*color,bool graph[101][101],int n,int clr)
    {
        //Check if its not same node , there do not exists direct edge
        //and color of adjacent node is not same as color that we are 
        //going to assign now
        for(int k=0;k<n;k++){
            if(k!=node && graph[k][node] && color[k]==clr){
                return false;
            }
        }
        return true;
    }
    bool solve(int node,int *color,int m,int n,bool graph[101][101])
    {
        //check if u have reached end
        if(node==n)return true;
        
        //Run a loop over all m-colors to check whether its possible to color
        for(int i=1;i<=m;i++){
            //i here is current color assigned by for loop
            if(isSafe(node,color,graph,n,i)){
                //If safe , then assign the required color
                color[node]=i;
                if(solve(node+1,color,m,n,graph)){
                    return true;
                }
                else color[node]=0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        //color array so that we can check if its safe to color 
        //particular node with particular color
        int color[n]={0};
        return solve(0,color,m,n,graph);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends