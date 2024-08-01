class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        int n=details.size();
        for(int i=0;i<n;i++){
            char c1=details[i][11];
            char c2=details[i][12];

            int age=c2-'0';
            age+=(c1-'0')*10;
            
            if(age>60) count++;
        }

        return count;
    }
};