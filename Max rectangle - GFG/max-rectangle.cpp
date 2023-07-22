//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    private:
    vector<int> findNextSmaller(int*arr, int n) 
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
    vector<int> findPrevSmaller(int*arr, int n) 
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
    int largestRectangleArea(int*heights,int n) {
        // int n=heights.size();

        //We need to create 2 arrays , one will store indices of 
        //prev smaller elements & another will store indices of next smaller elements

        vector<int>prev(n);
        vector<int>next(n);
        prev=findPrevSmaller(heights,n);
        next=findNextSmaller(heights,n);

        //Now iterate for each index element , find for max area from max length & breadth
        int area=INT_MIN;
        
        for(int i=0;i<n;i++){
            int l=heights[i];
            //One condition needs to be handled , when entire array does not not have next smaller element , then width will have whole array from that position
            if(next[i]==-1){
                next[i]=n;
            }

            int b=next[i]-prev[i]-1;

            int newArea=l*b;
            area=max(newArea,area);
        }

        return area;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        //Compute area for first row
        int area=largestRectangleArea(M[0],m);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                //Update rows by adding previous rows value
                if(M[i][j]!=0){
                    M[i][j]=M[i][j]+M[i-1][j];
                }else{
                    M[i][j]=0;
                }
            }
            //Entire rows are updated now
            area=max(area,largestRectangleArea(M[i],m));
        }
        
        return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends