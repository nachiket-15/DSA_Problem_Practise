//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size();
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            //Keep infinity for all those which are unreachable
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e9;
	            }
	            
	        }
	    }
	    
	    
	    
	    
	    
	    //Main algo
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                //k here acts as [via]
	                //matrix[i][j]=min(matrix[i][j],matrix[i][via]+matrix[via][j])
	                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    //Now replace infinity by -1 before returning
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	    
	    
	    
	    
	    
	}
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends