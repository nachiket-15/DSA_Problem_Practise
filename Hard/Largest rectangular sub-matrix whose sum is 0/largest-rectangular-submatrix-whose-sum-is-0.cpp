//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
        //Get the sizes of matrices
        
        int m=a.size();//No of rows
        int n=a[0].size();//No of columns
        
        int left=0,right=0,up=0,down=0;
        
        //Iterate a loop over all columns
        for(int i=0;i<n;i++)
        {
            //Create an array of size equal to no of rows
            vector<int>arr(m,0);
            
            //Iterate from current column to last
            for(int j=i;j<n;j++)
            {
                //In it , iterate on all rows 
                for(int k=0;k<m;k++)
                {
                    arr[k]+=a[k][j];
                    //That is sum of row elements till 
                }
                
                //Create an unordered map 
                unordered_map<long long ,int>map;
                map[0]=-1;
                
                int l=0,r=0;
                
                long long sum=0;
                
                //
                for(int k=0;k<m;k++)
                {
                    sum+=arr[k];
                    if(map.count(sum)){
                        if((k-map[sum]) > (r-l))
                        {
                            l=map[sum]+1;
                            r=k+1;
                        }
                    }
                    else{
                        map[sum]=k;
                    }
                }
                if((j-i+1)*(r-l) > (right-left)*(down-up)){
                  up = l;
                  down = r;
                  left = i;
                  right = j+1;
              }
                
            }
        }
        
         vector<vector<int>> result;
      
      for(int i=up; i<down; i++){
          vector<int> arr;
          
          for(int j=left; j<right; j++){
              arr.push_back(a[i][j]);
          }
          
          result.push_back(arr);
      }
      
      return result;
    }
};


//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends