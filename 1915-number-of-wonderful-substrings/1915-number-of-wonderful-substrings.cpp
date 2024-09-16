class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n=word.size();

        unordered_map<int,int> mp;
        mp[0]=1;
        int freq=0;
        long long count=0;
        for(int i=0;i<n;i++){
            char ch=word[i];
            int code=ch-'a';

            int temp=1;
            temp=temp<<code;
            freq=freq^temp;
            count+=mp[freq];
            mp[freq]++;
            // count++;
            // int currCount=0;
            //count how many with difference of one
            for(int j=0;j<10;j++){
                int mask=1;
                mask=mask<<j;

                int oneDiff=freq^mask;
                // currCount=;
                count+=(mp[oneDiff]);
            }

            // mp[freq]+=currCount;

        }

        return count;
    }
};