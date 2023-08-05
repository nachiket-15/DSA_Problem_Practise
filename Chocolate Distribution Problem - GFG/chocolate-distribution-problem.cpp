//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        //Sort the given array
        sort(a.begin(),a.end());
        
        //First allocate first m students with first m elements of array so
        //that first condition of atleast one packet is full filled
        long long i=0;
        long long p=m-1;
    
        long long ans=1e9;
        //Now iterate after p till end of array
        while(p<n){
            //Check for min difference between min and max allocation
            ans=min(ans,a[p++]-a[i++]);
        }
        return ans;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends