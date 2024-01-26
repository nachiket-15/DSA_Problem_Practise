//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool isSafe(int row,int col,vector<vector<int>>&board,int n){
        
        //Store original row & col
        int dr=row;
        int dc=col;
        
        //For Upper diagonal
        while(row>=0 && col>=0){
            if(board[row][col]==1){
                return false;
            }
            row--;
            col--;
        }
        
        row=dr,col=dc;
        
        //In same row
        for(int i=col;i>=0;i--){
            if(board[row][i]==1){
                return false;
            }
        }
        
        row=dr,col=dc;
        //For Lower diagonal
        while(row<n && col>=0){
            if(board[row][col]==1){
                return false;
            }
            row++;
            col--;
        }
        
        return true;
    }
    
    void solve(int col,vector<vector<int>>&ans,vector<vector<int>>&board,vector<int>temp,int n)
    {
        
        if(col==n){
            ans.push_back(temp);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                temp.push_back(row+1);
                board[row][col]=1;
                
                //Recursive call
                solve(col+1,ans,board,temp,n);
                
                //Backtracking
                board[row][col]=0;
                temp.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> nQueen(int n) {
        
        vector<vector<int>>ans;
        
        vector<vector<int>>board(n,vector<int>(n,0));
        
        vector<int>temp;
        solve(0,ans,board,temp,n);
        return ans;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends