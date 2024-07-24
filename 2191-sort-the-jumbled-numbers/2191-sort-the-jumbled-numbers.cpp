class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = mapping.size();

        int m = nums.size();

        vector<pair<int,int>>newVal;

        for(int i =0;i<m;i++)
        {   
            int num = nums[i];

            string result;
            if(num==0)
            {
                result+=to_string(mapping[0]);
            }
            while(num>0)
            {
                int digit = num%10;
                num/=10;
                int mappedDigit = mapping[digit];

                result+= to_string(mappedDigit);
                
            } 
                reverse(result.begin(), result.end());
                int val = stoi(result);
                newVal.push_back({val,i});
        }

        sort(newVal.begin(),newVal.end());

        vector<int>ans;
        for(auto it : newVal)
        {
            ans.push_back(nums[it.second]);
        }

        return ans;
    }
};