//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	   // My approach - but gave TLE
	   // vector<int>v1;
	   // vector<int>v2;
	    
	   // for(auto v:mat1)
	   // {
	   //     for(auto n:v)
	   //     {
	   //         v1.push_back(n);
	   //     }
	   // }
	    
	   // for(auto v:mat2)
	   // {
	   //     for(auto n:v)
	   //     {
	   //         v2.push_back(n);
	   //     }
	   // }
	    
	   // int cnt=0;
	    
	   // for(int i=0;i<v1.size();i++)
	   // {
	   //     for(int j=0;j<v2.size();j++)
	   //     {
	   //         if(v1[i]+v2[j]==x)cnt++;
	   //     }
	   // }
	    
	   // return cnt;
	   
	   unordered_map<int,int>map;
	   
	   for(auto v:mat1)
	   {
	       for(auto n:v)
	       {
	           map[n]++;
	       }
	   }
	   
	   int cnt=0;
	   
	   for(auto v:mat2)
	   {
	       for(auto n:v)
	       {
	           if(map.find(x-n)!=map.end())
	           {
	               cnt++;
	           }
	       }
	   }
	   
	   return cnt;
	}
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends