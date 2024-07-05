class MedianFinder {
public:
    priority_queue<int, 
    vector<int>, 
    greater<int>> pq2; // minPQ
    priority_queue<int> pq1; // maxPQ
    MedianFinder() {}

    void addNum(int num) {
        pq1.push(num);

        //balance if needed
        if(pq1.size()-pq2.size()>=2){
            pq2.push(pq1.top());
            pq1.pop();
        }

        //exchange top elements if needed
        if(!pq2.empty() && pq1.top()>pq2.top()){
            pq2.push(pq1.top());
            pq1.push(pq2.top());
            pq1.pop(); pq2.pop();
        }
    }

    double findMedian() {
        int n=pq1.size()+pq2.size();

        if(n%2!=0) return (double)pq1.top();
        else{
            double d=(double(pq1.top())+double(pq2.top()))/2;

            return d;
        }

        return -1;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */