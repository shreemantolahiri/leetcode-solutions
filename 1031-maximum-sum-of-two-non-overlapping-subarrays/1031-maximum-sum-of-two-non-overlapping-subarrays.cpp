class Solution {
public:
    vector<int> prefix;
    int sumOfK(int ind,vector<int>& nums,int k){
        int n=nums.size();
        n=min(ind+k-1,n-1);

        int sum=prefix[n];
        if(ind>0) sum-=prefix[ind-1];

        return sum;
        
    }
    int a; int b;
    int dp[1002][2][2];
    int solve(int ind,vector<int>& nums, int firstLen, int secondLen){
        if(ind>=nums.size()) return 0;
        if(firstLen==0 && secondLen==0) return 0;

        if(dp[ind][firstLen][secondLen]!=-1) return dp[ind][firstLen][secondLen];
        //pick -> two options
        int pick1=0;
        if(firstLen!=0){
            pick1=sumOfK(ind,nums,a)+solve(ind+a,nums,0,secondLen);
        }
        int pick2=0;
        if(secondLen!=0){
            pick2=sumOfK(ind,nums,b)+solve(ind+b,nums,firstLen,0);
        }

        //skip
        int skip=solve(ind+1,nums,firstLen,secondLen);


        return dp[ind][firstLen][secondLen]=max({pick1,pick2,skip});
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        a=firstLen; b=secondLen;
        memset(dp,-1,sizeof(dp));
        prefix.resize(nums.size(),0);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            prefix[i]=sum;
        }
        return solve(0,nums,1,1);
    }
};