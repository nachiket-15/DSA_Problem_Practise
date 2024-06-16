//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string S, int K) 
    {
        int left=0;
        int right=0;
        int maxLen=0;
        int n=S.length();
        int maxFreq=0;
        
        map<char,int>map;
        
        while(right<n)
        {
            //update for current character
            map[S[right]]++;
            //update maxFreq 
            maxFreq=max(maxFreq,map[S[right]]);
            
            //if curr substring - maxfreq is more than k , 
            //we need to trim substring from left
            while((right-left+1)-maxFreq>K)
            {
                map[S[left]]--;
                left++;
                //no need to update maxFreq variable 
                //as in len-maxFreq > k , even if maxFreq is decreased 
                //it will inc overall result only , so of no need
            }
            
            //if current susbstring length minus maxFreq 
            //is less than equal to replacements allowed 
            //then we update it 
            if((right-left+1) - maxFreq<=K)
            {
                maxLen=max(maxLen,(right-left+1));
            }
            
            right++;
        }
        return maxLen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends