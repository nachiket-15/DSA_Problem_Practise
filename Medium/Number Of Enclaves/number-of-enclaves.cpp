//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid){
        vis[row][col]=1;
        
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        
        int n=grid.size();//row
        int m=grid[0].size();//col
        
        for(int i=0;i<4;i++){
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow<n && ncol<m && nrow>=0 &&ncol>=0 && !vis[nrow][ncol]&&grid[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        /*We will first mark all boundaries as visited and then 
        count the number of enclaves */
        
        int n=grid.size();//row
        int m=grid[0].size();//col
        
        //First make a visited matrix
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        //Visit the boundaries and mark them visited
        for(int i=0;i<m;i++){
            //row
            if(!vis[0][i] && grid[0][i]==1){
                dfs(0,i,vis,grid);
            }
            
            if(!vis[n-1][i]&& grid[n-1][i]){
                dfs(n-1,i,vis,grid);
            }
            
        }
        for(int i=0;i<n;i++){
            //col
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,vis,grid);
            }
            
            if(!vis[i][m-1] && grid[i][m-1]==1)
                dfs(i,m-1,vis,grid);
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    count++;
                }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends