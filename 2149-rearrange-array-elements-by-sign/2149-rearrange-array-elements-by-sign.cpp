class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
	    vector<int>neg;
	    int n=nums.size();
	    vector<int>ans(n,0);

	    for(int i=0;i<n;i++){
	        if(nums[i]<0)
	            neg.push_back(nums[i]);
	        else
	            pos.push_back(nums[i]);
	    }
	    
	    int Psize=pos.size();
	    int Nsize=neg.size();
	    
	    
	    if(Psize>Nsize){
	        for(int i=0;i<Nsize;i++){
	            ans[2*i]=pos[i];
	            ans[2*i+1]=neg[i];
	        }
	        int index=2*Nsize;
	        for(int i=Nsize;i<Psize;i++){
	            ans[index++]=pos[i];
	        }
	    }
	    
	    
	    //else contains remainning cases as it may have Psize==Nsize and also Psize < Nsize
	    else {
	        for(int i=0;i<Psize;i++){
	            ans[2*i]=pos[i];
	            ans[2*i+1]=neg[i];
	        }

	        int index=2*Psize;
	        for(int i=Psize;i<Nsize;i++){
	            ans[index++]=neg[i];
	        }
	    }
	    
	    return ans;
    }
};