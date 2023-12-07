//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int cnt_distinct_elements(int arr[],int n){
        
    }
    
    int countDistinctSubarray(int arr[], int n)
    {
        unordered_map<int,int>freq;
        
        set<int>st;
        for(int i=0;i<n;i++)
            st.insert(arr[i]);
            
            
        //Get the number of distinct elements 
        int k=st.size();
        int ptr1=0,ptr2=0,cnt=0;
        
        while(ptr2<n){
            freq[arr[ptr2]]++;
            //Ask yourself why here while loop and not if condition
            
            //As we will potentially miss out on subarrays due to 
            //duplicate elements and we will eventually exhaust outer 
            //loop as ptr will get increment 
            while(k==freq.size()){
                //Increment with all possible subarrays till end
                cnt+=n-ptr2;
                //Remove element from start so as to slide window
                freq[arr[ptr1]]--;
                if(freq[arr[ptr1]]==0){
                    freq.erase(arr[ptr1]);
                }
                ptr1++;
            }
            ptr2++;
        }
        //for that see second test case 
        //There if in dry run u will notice that ptr1 takes only first
        //two elemets of array eventually missing last 3 elemets taking into subarrays 
        //individual subarrays 
        //In that case u miss 2 subarrays 4,2,4 and 2,4 from last 
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