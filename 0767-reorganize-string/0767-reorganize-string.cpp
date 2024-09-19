class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;

        for(int i=0;i<s.length();i++) mp[s[i]]++;

        priority_queue<pair<int,char>> pq;

        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        string res="";
        
        while(pq.size()>1){
            cout<<pq.size()<<endl;
            auto mostFreq=pq.top();
            pq.pop();
            auto secondMostFreq=pq.top();
            pq.pop();

            res+=mostFreq.second;
            res+=secondMostFreq.second;

            if(mostFreq.first>1){
                mostFreq.first--;
                pq.push(mostFreq);
            }
            if(secondMostFreq.first>1){
                secondMostFreq.first--;
                pq.push(secondMostFreq);
            }
        }

        if(pq.size()==1){
            if(pq.top().first>1) return "";
            else res+=pq.top().second;
        }

        return res;
    }
};