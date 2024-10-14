class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(auto it:nums){
            pq.push(it);
        }


        long long res=0;

        while(k--){
            int top=pq.top();
            pq.pop();
            res+=top;

            double d=(double)top/3;
            d=ceil(d);

            pq.push(int(d));
        }

        return res;
    }
};