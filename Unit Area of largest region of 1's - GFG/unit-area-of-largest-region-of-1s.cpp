//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    void dfs(int row,int col,int &count,vector<vector<int>>&vis,vector<vector<int>>& grid)
    {
        
        int n=grid.size();
        int m=grid[0].size();
        
        if(row<0 || col<0 || row>=n ||col>=m ||grid[row][col]==0||vis[row][col]==1){
            return;
        }
        
        vis[row][col]=1;
        count++;
        
        for(int nr=-1;nr<=+1;nr++){
            for(int nc=-1;nc<=+1;nc++){
                
                dfs(nr+row,nc+col,count,vis,grid);
                
            }
        }
        
    }
    int findMaxArea(vector<vector<int>>& grid) {
       
        int res=0;
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                /*this step is much importatnt , earlier i was declaring 
                count outside so was causing error, 
                we need everytime make count 0 before dfs call*/
                int count=0;
                
                if(grid[i][j]==1){
                    dfs(i,j,count,vis,grid);
                    res=max(res,count);
                    
                }
                
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends