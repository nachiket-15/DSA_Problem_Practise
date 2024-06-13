//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        
        /* TLE 
        //brute force
        int cnt=0;
        int n=s.length();
        //start of substring
        
        for(int i=0;i<n;i++)
        {
            int hash[3]={0};
            //end of substring
            for(int j=i;j<n;j++)
            {
                hash[s[j]-'a']=1;
                
                if(hash[0]+hash[1]+hash[2]==3)
                {
                    cnt++;
                }
            }
        }
        return cnt;
        */
        
        //solution referred 
        
        int left=0;
        int right=0;
        int n=s.size();
        int cnt=0;
        int arr[3]={0};
        
        while(right<n)
        {
            arr[s[right]-'a']++;
            
            while(arr[0] && arr[1] && arr[2])
            {
                cnt+=(n-right);
                arr[s[left]-'a']--;
                left++;
            }

            right++;
        }
        return cnt;
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
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends