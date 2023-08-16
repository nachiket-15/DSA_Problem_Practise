class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        //Done on my own :))
        int n=mat.size();//no of rows
        int m=mat[0].size();//no of columns

        vector<int>ans;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                bool flag=true;
                if(mat[i][j]){
                    //check for up,down,right,left

                    //up
                    if(i-1>=0){
                        if(mat[i-1][j]>mat[i][j]){
                            flag=false;
                        }
                    }
                    //down
                    if(i+1<n){
                        if(mat[i+1][j]>mat[i][j]){
                            flag=false;
                        }
                    }
                    //left
                    if(j-1>=0){
                        if(mat[i][j-1]>mat[i][j]){
                            flag=false;
                        }
                    }
                    //right
                    if(j+1<m){
                        if(mat[i][j+1]>mat[i][j]){
                            flag=false;
                        }
                    }

                }
                if(flag==true){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};