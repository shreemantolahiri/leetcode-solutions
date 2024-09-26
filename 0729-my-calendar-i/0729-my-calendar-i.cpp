class MyCalendar {
public:
    vector<pair<int, int>> nums;
    MyCalendar() {}

    bool book(int start, int end) { 
        //if overlap -> false
        int n=nums.size();
        for(int i=0;i<n;i++){
            int left=nums[i].first;
            int right=nums[i].second;

            if(start<right && left<end) return false;
        }
        nums.push_back({start,end});
        return true;
        
        }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */