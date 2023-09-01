//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    vector<int> findNextSmaller(long long arr[], int n) 
    { 
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> findPrevSmaller(long long arr[], int n) 
    { 
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        
        for(int i=0;i<n;i++){
            int curr=arr[i];
            
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    public:
    
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
        //We need to create 2 arrays , one will store indices of 
        //prev smaller elements & another will store indices of next smaller elements
        vector<int>prev(n);
        vector<int>next(n);
        prev=findPrevSmaller(heights,n);
        next=findNextSmaller(heights,n);

        //Now iterate for each index element , 
        //find for max area from max length & breadth
        long long int area=INT_MIN;
        
        for(int i=0;i<n;i++){
            long long int l=heights[i];
            //One condition needs to be handled ,
            //when entire array does not not have 
            //next smaller element , 
            //then width will have whole array from that position
            if(next[i]==-1){
                next[i]=n;
            }
            long long int b=next[i]-prev[i]-1;
            long long int newArea=l*b;
            area=max(newArea,area);
        }

        return area;
    }
};



//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends