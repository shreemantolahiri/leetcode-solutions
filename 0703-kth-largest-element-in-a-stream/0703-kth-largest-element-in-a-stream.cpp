class KthLargest {
public:
    int n;
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int> pq2;
    KthLargest(int k, vector<int>& nums) {
        n=k;
        for(int i=0;i<nums.size();i++){
            pq1.push(nums[i]);
        }
        while(!pq1.empty() && pq1.size()>=n){
            pq2.push(pq1.top());
            pq1.pop();
        }
    }
    
    int add(int val) {
        // cout<<pq1.top()<<" "<<pq2.top()<<endl;
        pq1.push(val);

        if(pq1.size()>0){
            pq2.push(pq1.top());
            pq1.pop();}

        return pq2.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */