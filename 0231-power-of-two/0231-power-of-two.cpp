class Solution {
public:

    bool isPowerOfTwo(int n) {
        //No which are power of two has only one set bit

        //we can simply remove set bit and check if its zero now

        if(n<=0)return 0;

        if((n&(n-1))==0)return 1;

        return 0;
    }
};