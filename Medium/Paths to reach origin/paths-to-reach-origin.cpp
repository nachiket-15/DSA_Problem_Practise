//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int ways(int x, int y)
    {
        //code here.
        int mod = 1e9 + 7;
        if (x == 0 || y == 0){
            return 1;
        }
        vector<vector<int>> vec (x + 1, vector<int> (y + 1, 0));
        for(int i = 1; i <= y; i++){
            vec[0][i] = 1;
        }
        for(int i = 1; i <= x; i++){\
            vec[i][0] = 1;
        }
        for (int i = 1; i <= x; i++){
            for(int j = 1; j <= y; j++){
                vec[i][j] = (vec[i - 1][j] + vec[i][j - 1]) % mod;
            }
        }
        return vec[x][y];
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends