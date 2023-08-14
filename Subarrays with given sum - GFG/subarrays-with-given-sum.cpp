//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int subArraySum(int nums[], int n, int k)
    {
    	unordered_map<int,int>map;
        map[0]=1;

        int preSum=0,cnt=0;

        for(int i=0;i<n;i++){
            preSum+=nums[i];

            int diff=preSum-k;
            cnt+=map[diff];
            map[preSum]+=1;
        }

        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>sum;
	    Solution ob;
	    cout<<ob.subArraySum(arr, n, sum);
	    cout<<'\n';
	}
	return 0;
}
// } Driver Code Ends