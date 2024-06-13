//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int left=0;
        int right=0;
        int n=s.length();
        int ans=-1;
        
        unordered_map<char,int>mp;
        
        while(right<n)
        {
            mp[s[right]]++;
            
            if(mp.size()==k)
            {
                ans=max(ans,right-left+1);
            }
            
            while(mp.size()>k)
            {
                mp[s[left]]--;
                if(mp[s[left]]==0)
                {
                    mp.erase(s[left]);
                }
                left++;
            }

            right++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends