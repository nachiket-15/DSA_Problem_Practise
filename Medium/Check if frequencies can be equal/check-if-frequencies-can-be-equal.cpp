//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool check(vector<int>v)
    {
        int n=v.size();
        
        for(int i=1;i<n;i++)
        {
            if(v[i]!=v[i-1])
            {
                return 0;
            }
        }
        
        return 1;
    }
	bool sameFreq(string s)
	{
	    unordered_map<char,int>mp;
	    
	    for(auto ch:s)
	    {
	        mp[ch]++;
	    }
	    
	    vector<int>v;
	    
	    for(auto n:mp)
	    {
	        v.push_back(n.second);
	    }
	    
	    
	    sort(begin(v),end(v));
	    
	    bool ans=check(v);
	    if(ans==1)return ans;
	    
	    
	    v[v.size()-1]-=1;
	    
	    return check(v);
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends