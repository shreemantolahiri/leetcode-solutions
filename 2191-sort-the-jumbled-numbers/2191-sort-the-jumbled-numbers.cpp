class Solution {
public:
    int mapped(int a,vector<int>& mapping){
        string s=to_string(a);
        int num=0;
        for(int i=0;i<s.length();i++){
            int curr=s[i]-'0';
            int map=mapping[curr];
            num=num*10+map;
        }
        
        // int mul=1;
        // while(a>0){
        //     int dig=a%10;
        //     num+=mapping[dig]*mul;
        //     a=a/10;
        //     mul*=10;
        // }

        return num;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),[&](int a,int b){
            int mappeda=mapped(a,mapping);
            int mappedb=mapped(b,mapping);

            if(mappeda==mappedb){
                return false;
            }
            else{
                return mappeda<mappedb;
            }
        });

        return nums;
    }
};