//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int row,int col,vector<string>&ans,vector<vector<int>>&visited,vector<vector<int>>m,int n,string move){
        
        //If you have reached your destination (BASE CASE)
        if(row==n-1 && col==n-1){
            ans.push_back(move);
            return;
        }
        
        //D , L , R , U
        int delrow[]={+1,0,0,-1};
        int delcol[]={0,-1,1,0};
        
        string temp="DLRU";
        
        for(int index=0;index<4;index++)
        {
            int nrow=row+delrow[index];
            int ncol=col+delcol[index];
            
            if(nrow>=0 && ncol>=0 && ncol<n &&nrow<n && m[nrow][ncol]==1 &&!visited[nrow][ncol]){
                visited[row][col]=1;
                solve(nrow,ncol,ans,visited,m,n,move+temp[index]);
                visited[row][col]=0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m) {
        int n=m.size();
        
        vector<string>ans;
        
        vector<vector<int>>visited(n,vector<int>(n,0));
        
        int row=0;
        int col=0;
        
        if(m[0][0]==1){
            solve(row,col,ans,visited,m,n,"");
        }
        
        return ans;
    }
};

    




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends