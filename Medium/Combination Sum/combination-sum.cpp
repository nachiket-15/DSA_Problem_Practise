//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
  
    void findComb(vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>&ds,int index){
        if(index==candidates.size()){
            if(target==0){
                sort(ds.begin(),ds.end());
                ans.push_back(ds);
            }
            return;
        }

        //Include
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            //Do not increment index in call ,as we want to pick that element again
            findComb(candidates,target-candidates[index],ans,ds,index);
            //Pop ds while backtracking
            ds.pop_back();
        }


        //Exclude
        findComb(candidates,target,ans,ds,index+1);

    }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<int> removeRepeated(vector<int>& a){
        int n = a.size();
        vector<int> unq;
        unordered_map<int, int> m;
    
        for(int i=0;i<n;i++){
            m[a[i]]++;
        }
        for(auto j: m){
            unq.push_back(j.first);
        }
        return unq;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>ds;
        
        // sort(candidates.begin(),candidates.end());
        
        
        candidates=removeRepeated(candidates);
        
        
        sort(candidates.begin(),candidates.end());
        
        int index=0;
        findComb(candidates,target,ans,ds,index);
        return ans;
        
        
    }
    
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends