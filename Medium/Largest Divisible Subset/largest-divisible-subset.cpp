//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
        
        vector<int>dp(n,1);//stores len of LIS till ith index
        vector<int>hash(n,1);//used to store idx of previous elements in LIS
        //For this sum , as we want divisible set , we first sort them
        sort(arr.begin(),arr.end());
        
        //We follow the same idea that we used while printing LIS
        for(int i=0;i<n;i++){
            //Initialize hash set with ith index everytime
            hash[i]=i;
            //Loop over prev indexes of current index
            for(int prev=0;prev<=i-1;prev++){
                //Check whether current element is divisible by any prev element &  if yes check if (1 + len of LIS till that prev) is greater than what currently it is
                if(arr[i]%arr[prev]==0 && 1+dp[prev]>dp[i]){
                    //if yes , update the dp array at that index
                    dp[i]=1+dp[prev];
                    //Store the prev node index in hash set, this will help us in printing the LIS
                    hash[i]=prev;
                }
            }
        }

        //Create ans var to store the maximum len from LIS
        int ans=-1;
        //This lasIdx var will store index of above ans var
        int lastIdx=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
                lastIdx=i;
            }
        }
        //These will act as starting point in creating LIS and will help storing it into temp vector further

        vector<int>temp;
        //Initially start by pushing the last element index into temp 
        temp.push_back(arr[lastIdx]);

        //loop till initialization condition (which occurs at end, so whole array will be traversed)
        while(hash[lastIdx]!=lastIdx){
            lastIdx=hash[lastIdx];
            temp.push_back(arr[lastIdx]);
        }
        //Now the LIS stored is in reverse form , so reverse it again
        reverse(temp.begin(),temp.end());

        //return the temp array
        return temp;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends