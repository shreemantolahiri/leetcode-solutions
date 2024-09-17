class Solution {
public:
    int sumOfK(int ind,vector<int>& nums,int k){
        int n=nums.size();
        n=min(ind+k,n);

        int sum=0;
        for(int i=ind;i<n;i++){
            sum+=nums[i];
        }
        // cout<<ind<<" to "<<ind+k<<" is= "<<sum<<endl;
        return sum;
    }
    int solve(int ind,vector<int>& nums, int firstLen, int secondLen){
        if(ind>=nums.size()) return 0;
        if(firstLen==0 && secondLen==0) return 0;
        //pick -> two options
        int pick1=0;
        if(firstLen!=0){
            pick1=sumOfK(ind,nums,firstLen)+solve(ind+firstLen,nums,0,secondLen);
        }
        int pick2=0;
        if(secondLen!=0){
            pick2=sumOfK(ind,nums,secondLen)+solve(ind+secondLen,nums,firstLen,0);
        }

        //skip
        int skip=solve(ind+1,nums,firstLen,secondLen);


        return max({pick1,pick2,skip});
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        

        return solve(0,nums,firstLen,secondLen);
    }
};