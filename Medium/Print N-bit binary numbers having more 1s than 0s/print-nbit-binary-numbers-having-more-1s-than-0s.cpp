//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    void solve(int n,int no_of_ones,int no_of_zeros,string ans,vector<string>&res)
    {
        if(n==0)
        {
            res.push_back(ans);
            return;
        }
        
        solve(n-1,no_of_ones+1,no_of_zeros,ans+"1",res);
        
        if(no_of_ones > no_of_zeros)
        {
            solve(n-1,no_of_ones,no_of_zeros+1,ans+"0",res);
        }
    }
	vector<string> NBitBinary(int n)
	{
	    //sol referred
	    vector<string>res;
	    int no_of_ones=0,no_of_zeros=0;
	    string ans="";
	  
	    solve(n,no_of_ones,no_of_zeros,ans,res);
	    return res;
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
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends