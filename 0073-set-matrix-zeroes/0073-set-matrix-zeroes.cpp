class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //This question is different from gfg set matrix zero
        //Referred solution for solving

        vector<vector<int>>temp=matrix;
        
        int n=matrix.size();//no of rows
        int m=matrix[0].size();//no of columns

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    //Make whole row zero 
                    for(int k=0;k<n;k++){
                        temp[k][j]=0;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    //Make whole column zero 
                    for(int k=0;k<m;k++){
                        temp[i][k]=0;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]=temp[i][j];
            }
        }
    }
};