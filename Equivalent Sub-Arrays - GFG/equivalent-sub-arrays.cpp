//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        unordered_map<int,int>freq;
        int ans_cnt=0;
        set<int>st;
        for(int i=0;i<n;i++)st.insert(arr[i]);
        
        int k=st.size();
        
        //Two pointer approach needs to be utilized
        int i=0,j=0;
        
        //We will use j for traversing 
        //i for cutting subarrays from front for next iteration
        while(j<n){
            freq[arr[j]]++;
            while(freq.size()==k){
                ans_cnt+=n-j;
                freq[arr[i]]--;
                
                if(freq[arr[i]]==0){
                    freq.erase(arr[i]);
                }
                
                i++;
            }
            j++;
        }
        
        return ans_cnt;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends