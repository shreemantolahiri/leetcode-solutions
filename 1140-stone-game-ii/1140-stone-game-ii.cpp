class Solution {
public:
    int dp[101][101][2];
    int solve(int ind,int m, bool turnA,vector<int>& piles){
        // cout<<ind<<" "<<m<<endl;
        int n=piles.size();
        if(ind>=piles.size()) return 0;
        // cout<<m<<endl;

        if(dp[ind][m][turnA]!=-1) return dp[ind][m][turnA];
        //if alice turn
        int lim=min((int)piles.size(),ind+2*m);
        // cout<<lim<<"  ind= "<<ind<<" m="<<m<<endl;
        int count=0;
        int ans=0;
        if(turnA) ans=-1;
        else ans=INT_MAX;
        for(int x=ind;x<lim;x++){
            count+=piles[x];
            
            int new_m=max(m,x-ind+1);
            // cout<<" for "<<x-ind+1<<endl;
            if(turnA){
                int temp=count+solve(x+1,new_m,false,piles);
                ans=max(temp,ans);
            }
            else{
                //bob turn
                int bob=solve(x+1,new_m,true,piles);
                ans=min(ans,bob);
            }
            //if alice takes x amount then bob can take 2(M,x)
        }

        return dp[ind][m][turnA]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        
        memset(dp,-1,sizeof(dp));
        return solve(0,1,true,piles);

    }
};