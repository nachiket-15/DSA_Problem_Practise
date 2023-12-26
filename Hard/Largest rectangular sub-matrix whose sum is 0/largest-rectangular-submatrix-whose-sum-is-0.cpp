//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution {
public:
    static vector<vector<int>> sumZeroMatrix(vector<vector<int>>& matrix) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        int startCol = 0, endCol = 0, startRow = 0, endRow = 0, maxArea = -1001;

        for (int i = 0; i < numCols; i++) {
            vector<int> colSum(numRows, 0);
            for (int j = i; j < numCols; j++) {
                for (int k = 0; k < numRows; k++) {
                    colSum[k] += matrix[k][j];
                }

                int startIndices[] = {0};
                int endIndices[] = {0};
                int len = maxLength(colSum, startIndices, endIndices);

                int area = (endIndices[0] - startIndices[0] + 1) * (j - i + 1);

                if (len > 0 && area > maxArea) {
                    startRow = startIndices[0];
                    endRow = endIndices[0];
                    startCol = i;
                    endCol = j;
                    maxArea = area;
                }
            }
        }

        vector<vector<int>> resultList;
        for (int i = startRow; i <= endRow; i++) {
            vector<int> rowList;
            for (int j = startCol; j <= endCol; j++) {
                rowList.push_back(matrix[i][j]);
            }
            resultList.push_back(rowList);
        }
        return resultList;
    }

private:
    static int maxLength(vector<int>& array, int startIndices[], int endIndices[]) {
        int sum = 0, maxLength = 0;
        unordered_map<int, int> sumIndexMap;

        for (int i = 0; i < array.size(); i++) {
            sum += array[i];

            if (array[i] == 0 && maxLength == 0) {
                startIndices[0] = i;
                endIndices[0] = i;
                maxLength = 1;
            }
            if (sum == 0) {
                if (maxLength < i + 1) {
                    startIndices[0] = 0;
                    endIndices[0] = i;
                }
                maxLength = i + 1;
            }
            if (sumIndexMap.find(sum) != sumIndexMap.end()) {
                int prevLength = maxLength;
                maxLength = max(maxLength, i - sumIndexMap[sum]);

                if (maxLength > prevLength) {
                    endIndices[0] = i;
                    startIndices[0] = sumIndexMap[sum] + 1;
                }
            } else {
                sumIndexMap[sum] = i;
            }
        }
        return maxLength;
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