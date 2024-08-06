class Solution {
public:
    int minimumPushes(string word) {
        //we have 8 keys
        vector<int> v(26,0);

        for(int i=0;i<word.size();i++){
            v[word[i]-'a']++;
        }

        sort(v.begin(),v.end(),greater<>());
        for(int i=0;i<26;i++){
            cout<<char('a'+i)<<" "<<v[i]<<endl;
        }
        int ct=0;
        int mul=1;
        for(int i=0;i<26;i++){
            if(i>0 && i%8==0) mul++;
            ct=ct+v[i]*mul;
            
        }

        return ct;

        


    }
};