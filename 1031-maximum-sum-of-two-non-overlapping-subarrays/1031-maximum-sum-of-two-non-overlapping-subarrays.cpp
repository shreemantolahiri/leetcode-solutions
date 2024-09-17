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
    int firstLen; int secondLen;
    int dp[1002][2][2];
    int solve(int ind,vector<int>& nums, int firstLenDone, int secondLenDone){
        if(ind>=nums.size()) return 0;
        if(firstLenDone==0 && secondLenDone==0) return 0;

        if(dp[ind][firstLenDone][secondLenDone]!=-1) return dp[ind][firstLenDone][secondLenDone];
        //pick -> two options
        int pick1=0;
        if(firstLenDone!=0){
            pick1=sumOfK(ind,nums,firstLen)+solve(ind+firstLen,nums,0,secondLenDone);
        }
        int pick2=0;
        if(secondLenDone!=0){
            pick2=sumOfK(ind,nums,secondLen)+solve(ind+secondLen,nums,firstLenDone,0);
        }

        //skip
        int skip=solve(ind+1,nums,firstLenDone,secondLenDone);


        return dp[ind][firstLenDone][secondLenDone]=max({pick1,pick2,skip});
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        this->firstLen = firstLen;  // Assign to class member
        this->secondLen = secondLen;  // Assign to class member
        memset(dp,-1,sizeof(dp));
        
        prefix.resize(nums.size(),0);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            prefix[i]=sum;
        }
        //dp
        return solve(0,nums,1,1);
    }
};