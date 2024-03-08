//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Solution referred
        
        int ans = 0;
        for(int i = 0; i<s.length(); i++){
            vector<int> frequency(26,0);
            
            for(int j = i; j<s.length(); j++){
                
                frequency[s[j] - 'a']++;
                
                int most_frequent = INT_MIN;
                int least_frequent = INT_MAX;
                
                for(int i = 0; i<26; i++){
                    
                    if(frequency[i] != 0){
                        most_frequent = max(most_frequent, frequency[i]);
                        least_frequent = min(least_frequent, frequency[i]);
                    }
                    
                }
                
                ans += (most_frequent - least_frequent);
            }
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
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends