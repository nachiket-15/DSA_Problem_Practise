class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res;
        for(int i=0;i<=n;i++){
            int cnt=0;
            int m=i;
            while(m>0){
                cnt++;
                m=m&(m-1);
            }
            res.push_back(cnt);
        }
        
        return res;
    }
};