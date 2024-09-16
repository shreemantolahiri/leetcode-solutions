class Solution {
public:
    int timeDifference(string &a, string &b){
        int h1=(a[0]-'0')*10+a[1]-'0';
        int m1=(a[3]-'0')*10+a[4]-'0';
        int h2=(b[0]-'0')*10+b[1]-'0';
        int m2=(b[3]-'0')*10+b[4]-'0';
        cout<<a<<" "<<b<<endl;
        cout<<h1<<" "<<m1<<" "<<h2<<" "<<m2<<endl;
        int mins1=h1*60+m1;
        int mins2=h2*60+m2;
        int fullDay=24*60;
        int miniMinutes=fullDay;

        
        if(mins1<mins2){
            miniMinutes=min({
                miniMinutes,
                mins2-mins1});

            if(mins1+fullDay>mins2){
                miniMinutes=min(miniMinutes,mins1+fullDay-mins2);
            }

        }
        else{
            miniMinutes=min({
                miniMinutes,
                mins1-mins2});

            if(mins2+fullDay>mins1){
                miniMinutes=min(miniMinutes,mins2+fullDay-mins1);
            }
        }

        return miniMinutes;
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int n=timePoints.size();
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            ans=min(ans,timeDifference(timePoints[i],timePoints[i-1]));
        }
        
        ans=min(ans,timeDifference(timePoints[0],timePoints[n-1]));
        return ans;
    }
};