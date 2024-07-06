class Solution {
public:
    int passThePillow(int n, int time) {
        int k=n-1;

        int dir=time/k;

        if(dir%2==0){
            //right direction
            return time%k+1;
        }
        else{
            //left direction
            return k-time%k+1;
        }
    }
};