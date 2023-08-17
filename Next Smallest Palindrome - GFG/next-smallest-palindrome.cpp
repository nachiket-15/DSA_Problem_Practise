//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    bool isAllNine(int num[],int n){
        for(int i=0;i<n;i++){
            if(num[i]!=9){
                return false;
            }
        }
        return true;
    }
    int isLess(int num[],int n){
        int i=(n-1)/2;
	    int j=n/2;
	    
	    while(i>=0){
	        if(num[i]<num[j])return 1;
	        else if(num[i]>num[j])return 0;
	        i--,j++;
	    }
	    //means was equal
	    return 1;
    }
	vector<int> generateNextPalindrome(int num[], int n) {
	    //Solution referred - Hence needs revision
	    
	    //Firstly check whether all array elements are 9
	    if(isAllNine(num,n)){
	        //If all are nine , its so easy then , just create a new vector 
	        //with one more size ( as 999 has nearest palindrome as 10001)
	        
	        //Intialize it with zeros
	        vector<int>ans(n+1,0);
	        //Make first and last element as 1
	        ans[0]=ans[n]=1;
	        //finally return your ans
	        return ans;
	    }
	    
	    //Add input array into ans array
	    vector<int>ans(num,num+n);
	    
	    
	    //Check if left part's reverse is greater than right ones
	    // 23545 , so mid is 5 , left is 23 , check if 32 is greater than 45
	    //If so we will directly replace 45 with its reverse 
	    //Otherwise if less , than palindrome formed would be less
	    int carry=isLess(num,n);
	    
	    //Now we will perform mirroring process
	    int i=(n-1)/2;
	    int j=n/2;
	    //First if carry is 1-means left part reverse is smaller than rightpart
	    while(i>=0){
	        //Check if carry is there : Increment by 1 the mid element
	        if(carry==1){
	            //Just check its 9 or not 
	            if(ans[i]==9){
	                //here puposefully carry is not made 0 so that in next iteration that carry is added and then it is made zero
	                ans[i]=0;
	            }
	            //else increment as usually & make carry 0
	            else ans[i]++,carry=0;
	        }
	        //Do reverse addition iteratively 
	        ans[j++]=ans[i--];
	    }
	    return ans;
	}

};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends