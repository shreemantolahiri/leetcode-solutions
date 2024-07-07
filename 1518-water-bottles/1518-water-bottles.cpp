class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int filled=0;
        int empty=numBottles;
        int count=numBottles;
        while(empty>=numExchange){
            cout<<empty<<endl;
            filled=empty/numExchange;
            empty=empty%numExchange;
            count+=filled;
            // filled=0;
            empty+=filled;
            filled=0;
            // cout<<empty<<endl;
        }

        return count;
    }
};