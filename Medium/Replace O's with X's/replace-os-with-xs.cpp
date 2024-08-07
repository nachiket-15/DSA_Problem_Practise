//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&mat){
        vis[row][col]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<4;i++){
            int nrow=delrow[i]+row;
            int ncol=delcol[i]+col;
            
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O')
            {
                dfs(nrow,ncol,vis,mat);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>vis(n,vector<int>(m,0));
        //traverse all boundaries first , apply dfs there 
        
        for(int j=0;j<m;j++){
            //Traversing along first row
            if(mat[0][j]=='O' && !vis[0][j]){
                dfs(0,j,vis,mat);
            }
            //Traversing along last row
            if(mat[n-1][j]=='O' && !vis[n-1][j]){
                dfs(n-1,j,vis,mat);
            }
        }
        
        for(int i=0;i<n;i++){
            //Traversing along first column
            if(mat[i][0]=='O' && !vis[i][0]){
                dfs(i,0,vis,mat);
            }
            //Traversing along last column
            if(mat[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,vis,mat);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends