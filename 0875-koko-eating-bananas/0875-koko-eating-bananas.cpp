class Solution {
public:
    bool canEat(vector<int>& piles, int h,long long  speed){
        long long hours=0;
        for(int i=0;i<piles.size();i++){
            double f=(double)piles[i]/speed;
            hours+=ceil(f);
            if(hours>h) break;
           
        }
        // cout<<hours<<"=hours  "<<h<<" mid="<<speed<<endl;
        if(hours<=h) return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long left=1;long long  right=INT_MIN;

        for(int i=0;i<piles.size();i++){
            // left=min(piles[i],left);
            right=max((long long  )piles[i],right);
        }
        // cout<<left<<" "<<right<<endl;
        while(left<=right){
            long long  mid=left+(right-left)/2;
            cout<<mid<<endl;
            if(canEat(piles,h,mid)==true){
                right=mid-1;
            }
            else left=mid+1;
        }

        return left;
    }
};