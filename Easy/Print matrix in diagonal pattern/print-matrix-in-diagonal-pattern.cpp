//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Submitting directly due to T2 
        int n = mat.size();
        int k = 0;
        vector<int> ans;
        while (k < n) {
            vector<int> temp;
            for (int i = k, j = 0; i >= 0 && j < n; i--, j++) {
                temp.push_back(mat[i][j]);
            }
            if (k % 2 != 0) {
                reverse(temp.begin(), temp.end());
            }
            ans.insert(ans.end(), temp.begin(), temp.end());
            k++;
        }
        
        int p = 1;
        while (p < n) {
            vector<int> temp;
            for (int i = n - 1, j = p; i >= 0 && j < n; i--, j++) {
                temp.push_back(mat[i][j]);
            }
            if (n % 2 != 0) {
                if (p % 2 != 0) {
                    reverse(temp.begin(), temp.end());
                }
            } else {
                if (p % 2 == 0) {
                    reverse(temp.begin(), temp.end());
                }
            }
            ans.insert(ans.end(), temp.begin(), temp.end());
            p++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends