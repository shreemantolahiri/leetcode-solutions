class Solution {
public:
    int sum(vector<int>& nums,int div){
        int s=0;
        for(int i=0;i<nums.size();i++){
            float f=nums[i];
            f=ceil(f/div);
            s+=f;
        }
        // cout<<"For div= "<<div<<" sum is "<<s<<endl;
        return s;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1; int right=INT_MIN;
        for(int i=0;i<nums.size();i++){
            right=max(right,nums[i]);
        }
        while(left<=right){
            int mid=left+(right-left)/2;
            int new_sum=sum(nums,mid);
            if(new_sum>threshold) left=mid+1;
            else{
                //even if equal
                right=mid-1;
            }
        }

        return left;

    }
};