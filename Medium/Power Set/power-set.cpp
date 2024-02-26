//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void solve(int idx,string s,vector<string>&ans,string temp)
	    {
	        if(idx>=s.length()){
	            ans.push_back(temp);
	            return;
	        }
	        //not take 
	        solve(idx+1,s,ans,temp);
	        
	        //take
	        temp+=s[idx];
	        solve(idx+1,s,ans,temp);
	            
	    }
	    
		vector<string> AllPossibleStrings(string s){
		    vector<string>ans;
		    string temp="";
		    solve(0,s,ans,temp);
		    sort(ans.begin(),ans.end());
		    vector<string>res;
		    
		    
            for(int i=1;i<ans.size();i++){
                res.push_back(ans[i]);
            }
        
        return res;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends