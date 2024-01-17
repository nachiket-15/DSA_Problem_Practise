
#include <bits/stdc++.h>
using namespace std;

bool static cmp(pair<int,int>a,pair<int,int>b){
    //If frequency is unequal , return one with more freq
    if(a.second!=b.second)
        return a.second>b.second;
    
    //else return one who is small in magnitude
    return a.first<b.first;
}
 
int main() {
    

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        
        
        
        
        //True code here
        unordered_map<int,int>mp;
        for(auto it:arr)mp[it]++;
        
        
        vector<pair<int,int>>v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
        
        
        for(int i=0;i<v.size();i++){
            for(int j=1;j<=v[i].second;j++){
                ans.push_back(v[i].first);
            }
        }
        
        
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    
}
return 0;
}