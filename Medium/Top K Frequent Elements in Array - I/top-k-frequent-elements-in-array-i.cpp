//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
       //We have to return top elements based on their frequency
       
       //maxheap
       priority_queue<pair<int,int>>pq;
       
       map<int,int>mp;
       
       for(int i=0;i<nums.size();i++)mp[nums[i]]++;
       
       for(auto it:mp)pq.push({it.second,it.first});
       
       vector<int>ans;
       
       while(!pq.empty() && k>0)
       {
           ans.push_back(pq.top().second);
           pq.pop();
           k--;
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends