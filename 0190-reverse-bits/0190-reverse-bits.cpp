class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        int shift=31;
        uint32_t checkLastBit=1;
        while(n>0){
            if((n&checkLastBit)==1){
                // cout<<shift<<endl;
                //it is a 1
                uint32_t bitmask=1;
                bitmask=bitmask<<shift;
                // cout<<bitmask<<endl;
                res=res|bitmask;
                n=n>>1;
                shift--;
            }
            else{
                //it is 0
                shift--;
                n=n>>1;
            }
        }

        return res;
    }
};