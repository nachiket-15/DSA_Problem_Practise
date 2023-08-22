//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        //Solution referred
        
        //array to store sum of each row & col
        vector<int>row;
        vector<int>col;
        int rowMaxSum=INT_MIN;
        int colMaxSum=INT_MIN;
        
        for(int i=0;i<n;i++){
            int rsum=0,csum=0;
            for(int j=0;j<n;j++){
                rsum=rsum+matrix[i][j];
                csum=csum+matrix[j][i];
            }
            //We will fill row & col array with sum of each row & col
            row.push_back(rsum);
            col.push_back(csum);
            
            if(rsum>rowMaxSum)rowMaxSum=rsum;
            if(csum>colMaxSum)colMaxSum=csum;
        }
        int operations_on_row=0;
        int operations_on_cols=0;
        //We need to return max operations as max operations will have maxSum
        //We are bound to make row/cols with maxSum as we can only increment matrix elements 
        
        for(int i=0;i<n;i++){
            operations_on_row+=(rowMaxSum-row[i]);
            operations_on_cols+=(colMaxSum-col[i]);
        }
        return max(operations_on_row,operations_on_cols);
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends