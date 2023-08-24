//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        
        long long left=0;
        long long right=n-1;
        long long maxleft=0;
        long long maxright=0;
        long long res=0;
        
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>maxleft){
                    maxleft=height[left];
                }
                else{
                    res+=maxleft-height[left];
                }
                left++;
            }else{
                if(height[right]>maxright){
                    maxright=height[right];
                }
                else{
                    res+=maxright-height[right];
                }
                right--;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends