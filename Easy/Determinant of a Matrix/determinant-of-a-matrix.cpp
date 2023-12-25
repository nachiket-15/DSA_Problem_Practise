//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        if(n==1)
            return matrix[0][0];
        
        int ans=0;
        
        //Traverse all columns from 0th row
        for(int i=0;i<n;i++)
        {
            //Create a second matrix - (formed from below wale elements)
            vector<vector<int>>second(n-1,vector<int>(n-1));
            
            //Traverse all rows from it 
            for(int j=1;j<n;j++){
                int row=0;
                
                //Traverse all columns from it 
                for(int k=0;k<n;k++){
                    
                    //In building second you have to skip the current column
                    if(k==i)continue;
                    
                    second[j-1][row++]=matrix[j][k];
                }
            }
            
            ans+=matrix[0][i]*determinantOfMatrix(second,n-1)*((i%2)?-1:1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends