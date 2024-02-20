//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int solve(string s,unordered_set<string>&st,vector<int>&dp,int index)
    {
        //base case 
        if(index==s.size()){
            return 1;
        }
        if(dp[index]!=-1)return dp[index];
        string temp;
        for(int i=index;i<s.size();i++){
            temp+=s[i];
            if(st.find(temp)!=st.end()){
                if(solve(s,st,dp,i+1)){
                    return dp[index]=1;
                }
            }
        }
        return dp[index]=0;
    }
    int wordBreak(string s, vector<string> &wordDict) {
        //Solution referred
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size()+1,-1);
        return solve(s,st,dp,0);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends