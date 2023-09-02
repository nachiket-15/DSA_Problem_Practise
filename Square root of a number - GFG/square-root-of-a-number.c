//{ Driver Code Starts
//Initial Template for C

#include<stdio.h>
  

// } Driver Code Ends
//User function Template for C
#define ll long long
long long int floorSqrt(long long int x) 
{
    //Today done on own
      ll low=0;
      ll high=x;
      ll ans=0;
      while(low<=high){
          ll mid=(low+high)/2;
          
          if(mid*mid<=x){
              ans=mid;
              low=mid+1;
          }else{
              high=mid-1;
          }
      }
      
      return ans;
}

//{ Driver Code Starts.

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long n;
		scanf("%ld", &n);
	
		printf("%ld\n", floorSqrt(n));
	}
    return 0;   
}

// } Driver Code Ends