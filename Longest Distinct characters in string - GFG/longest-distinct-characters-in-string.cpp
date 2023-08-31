//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    //solution referred
    //Using sliding window 
    int left=0;
    int right=0;
    int count=0;
    int end=S.length();
    unordered_map<char,int>cmap;
    
    while(right<end){
        if(cmap[S[right]]>=1){
            //reducing window from front
            cmap[S[left]]--;
            left++;
            continue;
        }
        cmap[S[right]]++;
        count=max(count,right-left+1);
        right++;
    }
    return count;
}