//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int atMostK(vector<int>&nums,int N,int k)
    {
        int i=0;
        int res=0;
        unordered_map<int,int>count;

        for(int j=0;j<nums.size();j++)
        {
            count[nums[j]]++;
            if(count[nums[j]]==1)
            {
                k--;
            }

            while(k<0)
            {
                count[nums[i]]--;
                
                if(count[nums[i]]==0)
                {
                    k++;
                }
                i++;
            }

            res+=j-i+1;
        }
        return res;
    }
    int subarrayCount(vector<int> &arr, int N, int k) {
        // code here
        return atMostK(arr,N,k)-atMostK(arr,N,k-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends