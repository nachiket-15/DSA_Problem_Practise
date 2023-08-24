//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long findsum(int arr[],int n){
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        return sum;
    }
    bool isPossible(int arr[],int n, int k,long long boards){
        long long paintersCount=1;
        long long boardsPainted=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]+boardsPainted <= boards){
                boardsPainted+=arr[i];
            }else{
                paintersCount++;
                if(paintersCount>k ||arr[i]>boards)return 0;
                boardsPainted=arr[i];
            }
        }
        return 1;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        //k is no of painters hired for work
        //Each painter takes 1 unit time to paint 1 unit of board
        long long low=*max_element(arr,arr+n);
        long long high=findsum(arr,n);
        
        while(low<=high){
            long long mid=(low)+(high-low)/2;
            //mid is no of boards
            if(isPossible(arr,n,k,mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends