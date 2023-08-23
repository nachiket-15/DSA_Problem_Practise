//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    //Solution referred - Brute force
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>ans;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            //Check if first character matches, 
	            if(grid[i][j]==word[0]){
	            //if yes traverse in 8-Directions to search for others
	            bool flag=false;
	            for(int k1=-1;k1<=1;k1++){
	                for(int k2=-1;k2<=1;k2++){
	                    if(flag)break;
	                    if(k1==0 && k2==0)continue;
	                    else{
	                        int di=i;//direction in i(x)
    	                    int dj=j;//direction in j(y)
    	                    int l=0;
    	                    //check if other characters of word match
    	                    for(l=0;l<word.size();l++){
    	                        if(di>=0 && dj>=0 && di<n &&dj<m && grid[di][dj]==word[l]){
    	                            di=di+k1;
    	                            dj=dj+k2;
    	                        }else{
    	                            break;
    	                        }
    	                    }
    	                    
    	                    if(l==word.size()){
    	                        flag=true;
    	                        ans.push_back({i,j});
    	                    }
	                    }
	                }
	            }
	                
	            }
	        }
	    }
	    //the flag variable is used to control the process of searching 
	    //for the entire word in different directions from the current 
	    //starting cell. If the word is found in any direction, 
	    //the flag is set to true, and the loop stops checking other 
	    //directions for the same starting cell(as we need only starting idx in ans)
	    sort(ans.begin(),ans.end());   
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends