//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(vector<string>&ans,int index,string S){
        if(index>=S.size()){
            ans.push_back(S);
            return;
        }
        
        //Here we want permutations of string 
        //So we apply swapping logic 
        for(int i=index;i<S.size();i++){
            swap(S[index],S[i]);
            solve(ans,index+1,S);
            swap(S[index],S[i]);
        }
    }
    vector<string> permutation(string S)
    {
        vector<string>ans;
        int index=0;
        solve(ans,index,S);
        sort(ans.begin(),ans.end());
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
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends