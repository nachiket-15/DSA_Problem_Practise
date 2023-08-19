//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>>&ans,vector<vector<int>>& image,int sr,int sc,int newColor,int initialColor){
        ans[sr][sc]=newColor;
        
        int n=image.size();
        int m=image[0].size();
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nrow=sr+delrow[i];
            int ncol=sc+delcol[i];
            
            if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && ans[nrow][ncol]!=newColor &&image[nrow][ncol]==initialColor){
                dfs(ans,image,nrow,ncol,newColor,initialColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int initialColor=image[sr][sc];
        vector<vector<int>>ans=image;
        dfs(ans,image,sr,sc,newColor,initialColor);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends