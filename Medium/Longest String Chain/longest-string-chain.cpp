//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool compareStrings(string&s1,string&s2){
    //If length of s1 is not greater than s2 by 1,then return false
    if(s1.length()!=s2.length()+1){
        return false;
    }
    //
    int first=0;
    int second=0;

    while(first<s1.length()){
        if(s1[first]==s2[second]){
            first++,second++;
        }else {
            first++;    
        }
    }

    if(s1.length()==first && s2.length()==second)return true;

    return false;

}
static bool comp(string &s1,string &s2){
    return s2.length()>s1.length();
}
    int longestChain(int n, vector<string>& arr) {
        // Code here
        // int n=arr.size();
    
    sort(arr.begin(),arr.end(),comp);
    vector<int>dp(n,1);
    

    for(int i=0;i<n;i++){
        for(int prev=0;prev<=i-1;prev++){
            if(compareStrings(arr[i],arr[prev]) && 1+dp[prev]>dp[i]){
                dp[i]=1+dp[prev];

            }
        }
    }
    
    return *max_element(dp.begin(),dp.end());
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends