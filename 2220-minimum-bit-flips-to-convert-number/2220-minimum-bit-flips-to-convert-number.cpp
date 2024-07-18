class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        int x=start^goal;
        while(x>0){
            int checkOne=x&1;
            if(checkOne==1) count++;

            x=x>>1;
        }

        return count;
    }
};