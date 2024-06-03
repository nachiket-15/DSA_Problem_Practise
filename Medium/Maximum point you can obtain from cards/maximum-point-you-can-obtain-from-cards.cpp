//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &nums, int N, int k) {
        //hats off to striver
        int lsum=0,rsum=0,maxSum=0;
        
        for(int i=0;i<k;i++)
        {
            lsum=lsum+nums[i];
            maxSum=max(maxSum,lsum);
        }
        
        int rightIdx=N-1;
        
        for(int i=k-1;i>=0;i--)
        {
            lsum=lsum-nums[i];
            rsum=rsum+nums[rightIdx--];
            maxSum=max(lsum+rsum,maxSum);
        }
        
        return maxSum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends