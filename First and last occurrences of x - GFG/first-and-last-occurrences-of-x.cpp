//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
int UpperBound(int arr[],int low,int high,int x,int n){
    int ans=n;
    
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
    
}
int LowerBound(int arr[],int low,int high,int x,int n){
    int ans=n;
    
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
    
}

vector<int> find(int arr[], int n , int x )
{

   int ub=UpperBound(arr,0,n-1,x,n);
   int lb=LowerBound(arr,0,n-1,x,n);
   
   //If element is not found in array it will return n 
   //(see above func we have set them values as n)
   //& if theres no lower bound , u wont get upper bound too
   //Lower bound is imp to exist as it contains equal condition and
   //here we are to find occurrences of specific element
   if(lb==n || arr[lb]!=x)return {-1,-1};
   
    vector<int>ans(2,-1);
    
    ans[0]=lb;
    ans[1]=ub-1;
    
    return ans;
}
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends