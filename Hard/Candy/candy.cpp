//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &rating) {
        //We initially need to allocate one candy to everyone
        vector<int>candy(N,1);
        
        //To ensure fair candy allocation , we will traverse 
        //forward as well as backward
        
        //fwd
        for(int i=1;i<N;i++){
            if(rating[i]>rating[i-1]){
                candy[i]=candy[i-1]+1;
            }
        }
        //bckwd
        for(int i=N-1;i>0;i--){
            if(rating[i-1]>rating[i]){
                candy[i-1]=max(candy[i]+1,candy[i-1]);
            }
        }
        
        int ans=accumulate(candy.begin(),candy.end(),0);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends