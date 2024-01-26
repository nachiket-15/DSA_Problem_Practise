//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isPalindrome(string S,int start,int end)
    {
        while(start<=end)
        {
            if(S[start++]!=S[end--]){
                return 0;
            }
        }
        return 1;
    }
    void func(int index,string S,vector<vector<string>>&ans,vector<string>&temp)
    {
        if(index==S.length()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=index;i<S.length();i++)
        {
            int start=index;
            int end=i;
            
            if(isPalindrome(S,start,end))
            {
                temp.push_back(S.substr(start,end-start+1));
                func(i+1,S,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>>ans;
        vector<string>temp;
        
        int index=0;
        
        func(index,S,ans,temp);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends