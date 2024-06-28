class Solution {
public:
    int mySqrt(int x) {
        int left=1; int right=x/2;
        if(x==0 || x==1) return x;

        int ans=0;
        while(left<=right){
            long long mid=left+(right-left)/2;

            if(mid*mid<=x){
                ans=mid;
                left=mid+1;
            }
            else{
                //square is bigger
                right=mid-1;
            }
        }

        return ans;
    }
};