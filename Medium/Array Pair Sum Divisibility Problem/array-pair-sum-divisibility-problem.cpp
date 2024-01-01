//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        map<int,int>map;
        
        for(int i=0;i<nums.size();i++)
        {
            //We want to calculate , how much should we add to nums[i]
            //So as to make it divisible by k
            
            int c=nums[i]%k;
            int req=(k-c)%k;
            
            //If already present , we will reduce its frequency
            if(map.count(req)){
                map[req]--;
                
                //If its frequency has become 0 , then remove it from map
                if(map[req]==0){
                    map.erase(req);
                }
            }else{
                map[c]++;
            }
        }
        
        return map.size()==0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends