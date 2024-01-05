//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int mod=(1e9+7);
	int TotalWays(int N)
	{
	    
	    //Intuition behind this solution is recursion
	    //But here we can implement it using for loop
	    
	    //While constructing buildings , we have two options , to 
	    //keep space as it is or to build an building 
	    
	    //But due to constraint , a building can be made after space
	    //But space can be after building too and after previous space too 
	    
	    //Due to this intution we can come towards 
	    //countSpace(N)=countBuilding(N-1)+countSpace(N-1)
	    //countBuilding(N)=countSpace(N-1)
	    
	    
	    long long prev1=1,prev2=1;
	    
	    for(int i=1;i<=N;i++)
	    {
	        long long totalWays=(prev1+prev2)%mod;
	        prev2=prev1;
	        prev1=totalWays;
	    }
	    
	    return (prev1*prev1)%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends