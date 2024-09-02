class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalSum=0;

        int n=chalk.size();
        for(int i=0;i<n;i++){
            totalSum+=chalk[i];
        }

        k=k%totalSum;

        for(int i=0;i<n;i++){
            if(k<chalk[i]) return i;

            k-=chalk[i];
        }

        return 0;
    }
};